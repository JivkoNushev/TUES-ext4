#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <err.h>

#include "file_sys_t.h"
#include "utils.h"
#include "wrapper_functions.h"

int main(int argc, char const *argv[])
{
    if(4 != argc) 
    {
        errx(EXIT_FAILURE, "Invalid number of arguments");
    }

    // 1) Път до файл, върху който ще инициализирате файлова система.
    int fd_tofs = -1;

    if(-1 == (fd_tofs = open(argv[1], O_RDWR)))
    {
        fd_tofs = err_open_fd(open(argv[1], O_RDWR | O_CREAT)); // give permissions maybe
    }

    //int dataBlock_count = count_bytes(fd_tofs);


    // 2) Бройката inode-ове в тази файлова система.
    int inode_count = str_to_int(argv[2]);

    if(inode_count < 1)
    {
        errx(EXIT_FAILURE, "Invalid number of inodes");
    }

    // 3) Големината на data block-овете в тази файлова система.
    int dataBlock_size = str_to_int(argv[3]);

    if(inode_count < 1)
    {
        errx(EXIT_FAILURE, "Invalid dataBlock size");
    }



    file_sys_t fs = init_FS(inode_count, dataBlock_size);


    return 0;
}