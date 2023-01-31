#include <stdio.h>
#include <stdlib.h>

#include "file_sys_t.h"
#include "wrapper_functions.h"

file_sys_t init_FS(int inode_count, int dataBlock_size)
{
    file_sys_t fs;

    header_t header = {TUESext4, inode_count, 0, dataBlock_size, 0};
    fs.header = header;

    fs.inode_table = (inode_t*)err_allocate(malloc(sizeof (inode_t) * inode_count));
    fs.dataBlock_table_bitmap = (u_int8_t*)err_allocate(malloc(inode_count / 8));

    fs.dataBlock_table = NULL;
    fs.dataBlock_table_bitmap = NULL;

    return fs;
}