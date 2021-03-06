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

//定义延迟函数；
#define msleep(x)	usleep( x*1000 )

//方块的结构体；
struct block
{
	int W ;		//方块的宽度；
	int H ;		//方块的高度；
	int row ;	//方块的起始坐标row，col；
	int col ;
	int drow ;	//方块的移动方向drow，dcol；
	int dcol ;
	
	void( * show)(struct block block);	//方块显示；
	void( * clear)(struct block block);	//方块清除；
	void( * move)(struct block *block);	//方块移动；
};

//函数声明;
void show_background( void );
void show_block( struct block block );
void clear_block( struct block block );
void move_block(struct block *block );

//主函数；
int main(void)
{
	struct block b1 = { 3,1,5,5,1,1, show_block , clear_block , move_block };
	system("clear");
	show_background();
	printf( "\033[?25l" );
	while(1)
	{
		b1.show(b1);
		msleep(250);
		b1.clear(b1);
		b1.move(&b1);
	}
	return 0;
}

//显示方块；
void show_block(struct block block)
{
	int i,j;
	for( i = 0 ; i < block.H ; i++ )
	{
		for( j = 0 ; j < block.W ; j++ )
		{
			printf("\033[%d;%dH \033[43m \033[0m" , block.row + i , block.col + j );
		}
	}
	fflush(stdout);
}

//清除方块；
void clear_block(struct block block)
{
	int i,j;
	for( i = 0 ; i < block.H ; i++ )
	{
		for( j = 0 ; j < block.W ; j++ )
		{
			printf("\033[%d;%dH \033[0m" , block.row + i , block.col + j);
			printf("\033[2J");
			show_background();
		}
	}
	fflush(stdout);
}

//移动方块；
void move_block(struct block *block)
{
	if( block->row < 3 || block->row > (ROW-block->H-1) )
		block->drow = -block->drow;
	if( block->col < 3 || block->col > (COL-block->W-1) )
		block->dcol = -block->dcol;

	block->row += block->drow;
	block->col += block->dcol;
}

//显示背景；
void show_background(void)
{
	int i,j;
	//画出上下左右边框;
	for( i = 1 ; i <= ROW ; i++ )
	{
		printf( "\033[%d;1H \033[43m \033[0m" , i );
		printf( "\033[%d;%dH \033[43m \033[0m", i , COL );
	}

	for( i = 1 ; i <= COL ; i++ )
	{		
		printf( "\033[1;%dH \033[43m \033[0m" , i );
		printf( "\033[%d;%dH \033[43m \033[0m", ROW , i );
	}
}

