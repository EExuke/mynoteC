/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : StrPress.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : Unpress string for read
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : str
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
    char * str = "A3B4C2D1" ;
    //char * str = "A6B9C6D3" ;
    //char * str = "A9B9C9D9e9f9g9" ;       //待解压的字符串
    int str_lenght = 0 ;
    int i ;
    static int count ;
    char * p = NULL ;
    char ch ;

    p = malloc(1000) ;
    /*判断字符串有没有到最后一个字符 为0，如果到了，退出循环*/
    while( * str++ != '\0')
    {
        str_lenght = atoi(str) ;    //atoi输出str字符串中的第一组整数；
        //指向前一个字符
        str-- ;
        while(count<1000)
        {
            //这一步将获取到字符串中的第一个数字，也就是表示个数的数字；
            //然后赋值给分配的内存空间
            for(i=0 ; i<str_lenght ; i++)
            {
                p[count] = * str ;
                count++ ;
            }

            //让指针的地址偏移+2 ，偏移到下一个字符位置
            str += 2 ;
            break ;
        }
    }
    //打印解压后的数据
    printf("%s\n" , p) ;
    //释放内存
    free(p) ;
    return 0;
}

