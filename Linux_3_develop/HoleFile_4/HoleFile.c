/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : HoleFile.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : Create hole file 
** ************************************************************************** */

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
    int offset;
    fd = fopen("tmp" , "w+");
    if (fd == NULL)
    {
        printf("fopen fair! \n");
        return -1;
    }
    /*end向后追加1G空间*/
    fseek(fd , 1024ll*1024ll*1024ll , SEEK_END);
    fwrite("" , 1 , 1 , fd);
    fclose(fd); 
    return 0;
}

