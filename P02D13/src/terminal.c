struct termios org_opts;

void setup_terminal(void) {
  struct termios new_opts;
  tcgetattr(STDIN_FILENO, &org_opts);
  memcpy(&new_opts, &org_opts, sizeof(new_opts));
  new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | ICRNL);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
}

void reset_terminal(void) {
  tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
}
