#ifndef FILE_T
#define FILE_T

#include <stdlib.h>

typedef struct inode_t
{
    u_int32_t link_count; // reserved
    u_int32_t permissions;
    u_int32_t owner;
    u_int32_t group;
    u_int64_t size;
    u_int64_t atime; // reserved
    u_int64_t ctime; // reserved
    u_int64_t mtime; // reserved
    
    u_int64_t content[14];
    
    u_int64_t reserved;

} inode_t;

typedef enum FSTYPE{TUESext4}FSTYPE;

typedef struct header_t
{
    u_int64_t fstype;
    u_int64_t inodes_count;   
    u_int64_t dataBlocks_count;   
    u_int32_t dataBlocks_size;

    u_int32_t reserved[9];

} header_t;

typedef struct file_sys_t
{
    header_t header;
    inode_t* inode_table;
    u_int8_t* inode_table_bitmap; // size: (Inodes_Count / 8)
    u_int8_t* dataBlock_table_bitmap; // size: (DataBlocks_Count / 8)
    u_int8_t* dataBlock_table; // size: DataBlocks_Count * DataBlock_size

} file_sys_t;



file_sys_t init_FS(int inode_count, int dataBlock_size);


#endif