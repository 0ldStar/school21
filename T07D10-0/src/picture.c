#include <stdio.h>

#define N 15
#define M 13

void transform(int* buf, int** matr, int n, int m);
void make_picture(int** picture, int n, int m);
void reset_picture(int** picture, int n, int m);
void output(int** matrix, int width, int height);

int main() {
    int picture_data[N][M];
    int* picture[N];
    transform((int*)picture_data, picture, N, M);
    make_picture(picture, N, M);
    output(picture, N, M);
    return 0;
}

void output(int** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width - 1) printf(" ");
        }
        if (i != height - 1)printf("\n");
    }
}

void make_picture(int** picture, int n, int m) {
    int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int tree_trunk[] = { 7, 7, 7, 7 };
    int tree_foliage[] = { 3, 3, 3, 3 };
    int sun_data[3][3] = { { 6, 6, 6 }, { 0, 6, 6 }, { 6, 0, 6 } };

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
    int length_tree_trunk = sizeof(tree_trunk) / sizeof(tree_trunk[0]);
    int length_tree_foliage = sizeof(tree_foliage) / sizeof(tree_foliage[0]);
    int length_sun_data = sizeof(sun_data[0]) / sizeof(sun_data[0][0]);

    for (int i = 0; i < length_tree_trunk; i++) {
        picture[10][2 + i] = tree_trunk[i];
        picture[6 + i][3] = tree_trunk[i];
        picture[6 + i][4] = tree_trunk[i];
    }
    for (int i = 0; i < length_tree_foliage; i++) {
        picture[3][2 + i] = tree_foliage[i];
        picture[4][2 + i] = tree_foliage[i];
        picture[2 + i][3] = tree_foliage[i];
        picture[2 + i][4] = tree_foliage[i];
    }
    for (int j = 0; j < length_sun_data; j++) {
        picture[1][7 + j] = sun_data[1][j];
        picture[4][7 + j] = sun_data[1][j];
        picture[1][9 + j] = sun_data[0][j];
    }
    for (int j = 0; j < length_sun_data; j++) {
        picture[4 - j][9] = sun_data[1][j];
        picture[4 - j][10] = sun_data[1][j];
        picture[4 - j][11] = sun_data[0][j];
    }
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
        picture[n / 2][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
        picture[i][m / 2] = frame_h[i];
    }
}

void reset_picture(int** picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int* buf, int** matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
