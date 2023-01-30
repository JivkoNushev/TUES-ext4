#include <stdio.h>
#include <stdlib.h>

#include <err.h>
#include <errno.h>

#include "wrapper_functions.h"

int err_open_fd(int fd)
{
    if(-1 == fd)
    {
        // free queue
        perror("open fd");
    }

    return fd;
}

void *err_allocate(void *p)
{
    if(NULL == p)
    {
        // free queue
        perror("allocate memory");
    }

    return p;
}

void err_message(const char *msg)
{
    // free queue
    errx(EXIT_FAILURE, msg);
}