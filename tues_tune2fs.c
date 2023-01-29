#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    if(4 != argc) perror("Invalid number of arguments");

    return 0;
}
