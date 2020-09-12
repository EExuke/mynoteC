/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : searchTable.c
 *     FIRST CREATION DATE    : 2019/07/12
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2019/07/12
 *     FILE DESCRIPTION       : use searchTable method to implement more function 
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/****************************************************************************
 *  Function Name : array[][10]
 *  Description   : Save the array[][] date in this table.
 *  Input(s)      : void
 *  Output(s)     : null
 *  Returns       : 0
 ****************************************************************************/
int array[][10] = {
                    0x03, 0x00, 0x00, 0x00, 0x00,   //第一列
                    0x00, 0x02, 0x00, 0x00, 0x00,

                    0x0C, 0x00, 0x00, 0x00, 0x00,   //第二列
                    0x00, 0x04, 0x00, 0x00, 0x00,

                    0x10, 0x00, 0x00, 0x00, 0x00,   //第三列
                    0x00, 0x08, 0x00, 0x00, 0x00,

                    0x60, 0x00, 0x00, 0x00, 0x00,   //第四列
                    0x00, 0x10, 0x00, 0x00, 0x00,

                    0x80, 0x01, 0x00, 0x00, 0x00,   //第五列
                    0x00, 0x10, 0x00, 0x00, 0x00,

                    0xAA, 0x55, 0x00, 0x00, 0xC0,   //结束列
                    0x00, 0x00, 0x00, 0x00, 0x00,
                  };

 /****************************************************************************
 *  Function Name : Print_led
 *  Description   : output the data from table.
 *  Input(s)      : &array
 *  Output(s)     : %3x
 *  Returns       : void
 ****************************************************************************/
void Print_led(int * array)
{
    int i ;
    for(i=0 ; i<10 ; i++)
    {
        printf("%3x" , *(array+i));
    }
    printf("\n");
}

 /****************************************************************************
 *  Function Name : delay_500ms
 *  Description   : used for delay time in 500ms.
 *  Input(s)      : void
 *  Output(s)     : NULL
 *  Returns       : void
 ****************************************************************************/
void delay_500ms(void)
{
    usleep(500000);
}

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : void
 *  Output(s)     : array[led]
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
    int i , j;
    int tick , count = 0 ;

    /*如果当数组第 count 行第0列等于0xAA，或者第count行第1行等于0x55时，退出，否则循环遍历数据
     */
    while( array[count][0] != 0xAA || array[count][1] !=0x55 )
    {
        //以首元素每次向后偏移10字节
        Print_led( (int * )(&array[0][0]+count*10) );
        delay_500ms();
        count++;
    }
    return 0;
}

