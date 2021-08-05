
static struct termios oldt, newt;
static int console_changed = 0;

void reset_terminal(void) {
    if (console_changed)
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    console_changed = 0;
}

void setup_terminal(void) {
    if (console_changed) return;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    console_changed = 1;
}


int read_console() {
    int rb;
    struct timeval tv;
    int retval;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    tv.tv_sec = 0; tv.tv_usec = 10000;
    retval = select(1, &rfds, NULL, NULL, &tv);
    if (!retval) {
       rb = 0;
    } else {
        if (FD_ISSET(STDIN_FILENO, &rfds)) {
          rb = getchar();
        } else {
          rb = 0;
        }
    }
    return rb;
}


int mygetchar() {
    int ret;
    do {
      ret = read_console();
    } while (ret == 0);
    return ret;
}
