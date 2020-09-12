/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : Createfiles.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : Create many files by once 
** ************************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>

char File_name[10];
static int i ;

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
    FILE * fd ;
    for(i=0 ; i<10 ; i++)
    {
        //利用sprintf函数重组文件名
        sprintf(File_name , "file%d" , i);
        fd = fopen(File_name , "w+");
        if(fd == NULL)
        {
            printf("open file fair ! \n");
            return -1 ;
        }
        printf("open file%d success\n" , i);
        fclose(fd);
    }
    return 0;
}

