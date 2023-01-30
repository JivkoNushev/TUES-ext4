#ifndef WRAPPER_FUNCTIONS
#define WRAPPER_FUNCTIONS

int err_open_fd(int fd);

void *err_allocate(void *p);

void err_message(const char *msg);

#endif