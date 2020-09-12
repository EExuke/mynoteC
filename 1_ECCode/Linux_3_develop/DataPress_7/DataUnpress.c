/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : DataUnpress.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : press 4bit Data to 8bit Data for press
** ************************************************************************** */

#include <stdio.h>

unsigned char tab[4] = {0xfe,0xf1,0x3e,0x3c};
unsigned char table[8] ;

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : void
 *  Output(s)     : table[8]
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
    int i , j ;
    int count = 0 ;
    for(i=0 ; i<8 ; i++)
    {
        if ( i % 2 == 0 )
            table[i] = tab[count] & 0x0f ;
        else if( i % 2 != 0)
        {
            table[i] = tab[count] & 0xf0 ;
            count++ ;
        }
    }
    for(i=0 ; i<8 ; i++)
        printf( "table[%d]:0x%x \n" , i , table[i] ) ;
    return 0;
}

