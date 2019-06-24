/*************************************************************************
    > File Name: block.c
  > Author: EExuke
  > Mail: 997028792@qq.com 
  > Created Time: 2019年06月22日 星期六 22时48分00秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

//定义窗口大小；
#define ROW	20
#define COL	60

void show_background(void);

//主函数；
int main(void)
{
	
	//system("clear");
	
	show_background();

	printf( "\033[? 251" );
	int i,j;
	for( i = 0 ; i < 5 ; i++ )
	{
		for( j = 0 ; j < 5 ; j++ )
		{
			printf("\033[%d; %dH\033[43m \033[0m" , 5 + i , 5 + j );
		}
	}

	for( i = 0 ; i < 5 ; i++ )
	{
		for( j = 0 ; j < 5 ; j++ )
		{
			printf("\033[%d; %dH \033[0m" , 5 + i , 5 + j);
		}
	}
}


//显示背景；
void show_background(void)
{
	int i,j;
	//画出上下左右边框;
	for( i = 1 ; i <= ROW ; i++ )
	{
		printf( "\033[%d; 1H \033[43m \033[0m" , i );
		printf( "\033[%d; %dH \033[43m \033[0m", i , COL );
	}

	for( i = 1 ; i <= COL ; i++ )
	{		
		printf( "\033[1; %dH \033[43m \033[0m" , i );
		printf( "\033[%d; %dH \033[43m \033[0m", ROW , i );
	}
}

