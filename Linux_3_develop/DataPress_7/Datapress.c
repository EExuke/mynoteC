/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : DataPress.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : change 8bit Data to 4bit Date for press
** ************************************************************************** */

#include <stdio.h>

unsigned char table[8] = {0x0e , 0xf0 , 0x01 , 0xf0 , 0x0e , 0x30 , 0x0c , 0x30};
int savebuf[4];

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : save[4]
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
    int i , j ;
    int low , high , count = 0 , beat_count , value ;
    count = 0 ;
    beat_count = 0 ;
    for(j=0 ; j<8 ; j++)
    {
        if (j%2 == 0)
            low = table[j] ;
        else
        {
            high = table[j] ;
            count++ ;
            savebuf[beat_count] = low | high ;
            beat_count++ ;
        }
    }
    for(i=0 ; i<4 ; i++)
        printf("savebuf[%d]:%x \n" , i ,savebuf[i]);
    return 0;
}

