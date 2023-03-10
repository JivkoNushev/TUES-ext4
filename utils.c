#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "wrapper_functions.h"
#include "utils.h"

// returns the string of a number
char *int_to_str(int n)
{
    char number[11] = {0};

    // split the number into digits
    int number_s = 0;
    for (number_s = 0; 0 != n; number_s++)
    {
        number[number_s] = '0' + n % 10;
        n /= 10;
    }

    // allocate memory for the string
    char *result = err_allocate((char *)malloc(number_s + 1));

    // put the digits in the correct order
    for (int i = 0; i < number_s; i++)
    {
        result[i] = number[(number_s - 1) - i];
    }
    result[number_s] = '\0';

    return result;
}

int str_to_int(const char *str)
{
    int number = 0;

    for(;'\0' != *str; str++)
    {
        if('9' < *str || *str < '0')
        {
            err_message("Invalid number to str");
        }
        number = number * 10 + (*str - '0');
    }

    return number;    
}

int count_bytes(int fd)
{
    int pos = lseek(fd, 0, SEEK_CUR);
    if(-1 == pos)
    {
        return -1;
    }

    if (-1 == lseek(fd, 0, SEEK_SET))
    {
        return -1;
    }

    int bytes_c = 0;
    if (-1 == (bytes_c = lseek(fd, 0, SEEK_END)))
    {
        return -1;
    }

    if (-1 == lseek(fd, pos, SEEK_SET))
    {
        return -1;
    }

    return bytes_c;
}