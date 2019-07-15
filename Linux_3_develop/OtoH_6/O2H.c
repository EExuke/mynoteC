/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : O2H.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : change .o file to .h file of C
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef unsigned char u8;
typedef unsigned int u32;

/****************************************************************************
 *  Function Name : GetBinSize
 *  Description   : Get size of the bin file.
 *  Input(s)      : The filename point.
 *  Output(s)     : int size
 *  Returns       : size
 ****************************************************************************/
u32 GetBinSize(char * filename)
{
    u32 size = 0;
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
 *  Function Name : OutPut_handle
 *  Description   : Output the .h file.
 *  Input(s)      : The *outpath , *buf ,size.
 *  Output(s)     : .h file.
 *  Returns       : null.
 ****************************************************************************/
void OutPut_handle(char * outpath , u8 * buf , u32 size)
{
    FILE * infile ;
    int i , j , k , n;
    int fd ;
    char pbuf[10] = {0} ;
    char size_buf[40] = {0} ;
    char mfgimage[4096*2] ;
    char * array = "static const unsigned char SPIflashimage[SPIIMAGESIZE] = {\n" ;
    /*写 .h 文件必要的信息*/
    char * Handle = "#ifndef SPI_FLASH_H \n " ;
    char * Handle1 = "#define SPI_FLASH_H \n " ;
    char * SPI_SPIflash = "#define SPI_SPIflash 0 \n " ;
    char * SIZE_4K = "#define SIZE_4K  4096*2 \n " ;
    char * line_T = "\n" ;
    char * EndIF = "\n#endif \n" ;
    if((infile = fopen(outpath,"wa+")) == NULL)
    {
        printf("\nCan not open the path: %s \n" , outpath);
        exit(-1);
    }
    k = 0;
    /*写文件头*/
    fwrite(Handle , strlen(Handle) , 1 , infile);
    fwrite(Handle1 , strlen(Handle1) , 1 , infile);
    fwrite(SPI_SPIflash , strlen(SPI_SPIflash) , 1 ,infile);
    sprintf(size_buf , "#define SPIIMAGESIZE %d\n" , size);
    fwrite(size_buf , strlen(size_buf) , 1 ,infile);
    fwrite(SIZE_4K , strlen(SIZE_4K) , 1 , infile);
    fwrite(array , strlen(array) , 1 , infile);
    for(i=0 ; i<size ; i++)
    {
        k++ ;
        sprintf(pbuf , "0x%02x" , buf[i]);
        fwrite(pbuf , strlen(pbuf) , 1 , infile);
        /*每读取16个byte就换行*/
        if(k != 16)
            fwrite("," , strlen(",") , 1 , infile);
        else
            fwrite("," , strlen(",") , 1 , infile);
        if(k == 16)
        {
            k = 0 ;
            fwrite("\n" , strlen("\n") , 1 , infile);
        }
    }
    fseek(infile , 0 ,SEEK_END);
    if(k == 0)
        fwrite("};" , strlen("};") , 1 , infile);
    else
        fwrite("\n};" , strlen("\n};") , 1 , infile);
    /*在infile文件*/
    fwrite(line_T , strlen(line_T) , 1 , infile);
    fwrite(EndIF , strlen(EndIF) , 1 , infile);
    fclose(infile);
}

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : src file , output path.
 *  Output(s)     : null
 *  Returns       : 0
 ****************************************************************************/
int main()
{
    u8 * buf = NULL ;
    u32 size ;
    int ret ;
    char srcbin[100] = {0} ;
    char dstfile[100] = {0} ;
    /*读取目标 .bin 文件*/
    printf("please input src file path \n");
    scanf("%s" , srcbin);
    /*创建一个 .h 头文件用于保存 bin 转C数组的文件*/
    printf("please input output path \n");
    scanf("%s" , dstfile);
    /*获取文件的大小*/
    size = GetBinSize(srcbin);
    printf("file_size:%d\n" , size);
    /*申请用于存放该文件的数组*/
    buf = (unsigned char *)malloc(sizeof(unsigned char) * size);
    printf("buf_size: %d->%d\n" , sizeof(buf)/sizeof(buf[0]) , size);
    /*读取文件*/
    //int fd = open(srcbin , O_RDWR | O_CREAT);
    FILE * fd = fopen(srcbin , "r+");
    if(fd == NULL)
    {
        printf("open file fair! \n");
        return -1 ;
    }
    ret = fread(buf , size , 1 , fd);
    if(ret < 0)
    {
        printf("read fair! \n");
        return -2 ;
    }
    /*制作头文件*/
    OutPut_handle(dstfile , buf , size);
    return 0;
}

