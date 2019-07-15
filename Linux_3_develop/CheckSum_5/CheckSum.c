/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : CheckSum.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : implementat CheckSum by C
** ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

/****************************************************************************
 *  Function Name : GetBinSize
 *  Description   : Get size of the bin file.
 *  Input(s)      : The filename point.
 *  Output(s)     : int size
 *  Returns       : size
 ****************************************************************************/
int GetBinSize(char * filename)
{
    int size = 0;
    FILE * fp = fopen(filename , "rb"); //打开文件，fp指向文件；
    if(fp)
    {
        fseek(fp , 0 , SEEK_END);   //从尾偏移0；
        size = ftell(fp);   
        fclose(fp);
    }
    return size;
}
/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc , char * argv[])
{
    FILE * fd ;
    int i ;
    int size ;
    size = GetBinSize("1.bin");
    int * buffer = NULL ;
    buffer = malloc(size);

    unsigned int one , two , three , four ;
    unsigned int checksum = 0 ;
    fd = fopen("1.bin" , "r+");
    if(NULL == fd)
    {
        printf("open file fail! \n");
        return -1;
    }
    fseek(fd , 0 , SEEK_SET);
    fread(buffer , size , 1 , fd);
    for(i=0 ; i<size/4 ; i++)
    {
        one = buffer[i] & 0xff;
        two = buffer[i] & 0xff00 >> 8;
        three = buffer[i] & 0xff0000 >> 16;
        four = buffer[i] & 0xff000000 >> 24;
        checksum += one + two + three + four ;
    }
    printf("%d->0x0%x \n" , checksum , checksum);
    free(buffer);
    return 0;
}

