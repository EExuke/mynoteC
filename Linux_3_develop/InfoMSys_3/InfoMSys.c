/*************************************************************************
  > File Name: InfoMSys.c
  > Description: The information manenge system is use "student" to descript,
  				but you can change it to any others in this framework;
  > Author: EExuke
  > Mail: 997028792@qq.com 
  > Created Time: 2019年06月29日 星期六 13时33分14秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define 	NR(x)   	(sizeof(x)/sizeof(x[10]))
#define 	UP      	0x001
#define 	DOWN    	0x002
#define 	LEFT    	0x003
#define 	RIGHT   	0x004
#define 	ESC     	0x005
#define 	ENTER   	0x007
#define 	UNKNOWN 	0x006
#define 	SIZE    	100

//信息结构类型定义
struct student
{
	char  name[20] ;
	int   id ;
	float score ;
};

int stucount ;//信息个数记录

//定义结构体数组
struct student array[SIZE] = {0} ;

//获取用户输入
int Get_User_input(int * index , int size);
//显示管理系统菜单
void showmenu(char * menu[] , int size , int index);
//信息添加
void stu_add(void);
//信息打印
void stu_show(void);
//信息查找
void stu_search(void);
//信息保存
void stu_save(void);
//信息加载
void stu_load(void);
//信息修改
void stu_modefi(void);
//信息删除
void stu_delete(void);

/**********************************************************************************
 * 主函数
 **********************************************************************************/
int main(void)
{
	char * menu[] = {
					"* 信息添加 *",
					"* 信息打印 *",
					"* 信息查找 *",
					"* 信息修改 *",
					"* 信息删除 *",
					"* 信息保存 *",		//至硬盘
					"* 信息导入 *",		//至内存
					"* 退出 *"
					};

	int index = 0 ;
	int ret ;
	showmenu(menu , NR(menu) , index) ;
	while(1)
	{
		ret = Get_User_input(&indexx , NR(menu)) ;
		if(ret == 1)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0 : stu_add()    ; break ;		//信息添加
				case 1 : stu_show()   ; break ;		//信息打印
				case 2 : stu_search() ; break ;		//信息查找
				case 3 : stu_modefi() ; break ;		//信息修改
				case 4 : stu_delete() ; break ;		//信息删除
				case 5 : stu_save()   ; break ;		//信息保存
				case 6 : stu_load()   ; break ;		//信息导入
				case 7 : return 0     ;
			}
		}

		//sleep(1) ;
		//index++  ;
		showmenu(menu , NR(menu) , index) ;
	}
	return 0 ;
}


/**********************************************************************************
 * 显示菜单界面的函数
 **********************************************************************************/
void showmenu(char * menu[] , int index)
{
	int i;
	system("clear");
	for( i=0 ; i<size ; i++ )
	{
		if(index == 1)
			printf("\033[%d;30H\033[30m\033[47m%s\033[0m", i+5 , menu[i]);
		else
			printf("\033[%d;30H\033[37m\033[40m%s\033[0m", i+5 , menu[i]);
	}
	fflush(stdout);
}

/**********************************************************************************
 * 获取用户输入的函数，返回键值
 **********************************************************************************/
static int_Get_User_Input(void)
{
	int type = UNKNOWN ;
	char ch ;

	system("stty - echo") ;
	system("stty - icanon") ;
	//获取用户输入，阻塞
	ch = getchar();
	if(ch == 'q')
			type = ESC ;
	if(ch == '' || ch == '\n')
			type = ENTER ;
	if(ch == '\033' && getchar() == '[')
	{
			switch(getchar())
			{
				case 'A' : type = UP ; break ;
				case 'B' : type = DOWN ; break ;
				case 'C' : type = RIGHT ; break ;
				case 'D' : type = LEFT ; break ;
			}
	}
	system("stty echo");
	system("stty icanon");
	return type ;
}

/**********************************************************************************
 * 接收到用户输入键值后进行处理的函数，返回标记
 **********************************************************************************/
int Get_User_input(int * index , int size)
{
	int type ;
	type = _Get_User_Input();

	switch(type)
	{
		case UP			 :	if( * index > 0) * index -= 1 ; break ;
		case DOWN		 :	if(	*	index	<	size - 1) * index += 1	;	break ;
		case LEFT		 :	break;
		case RIGHT 	 :	break;
		case ENTER	 :	return ENTER;
		case ESC		 :	return 1;
		case UNKNOWN :	break;
	}
	return 0 ;
}

/**********************************************************************************
 * 添加信息的函数
 **********************************************************************************/
void stu_add(void)
{
	system("clear");
	printf("								学生信息添加\n");

	if(student >= SIZE)
			printf("学生信息已满\n");
	printf("学生姓名 ：");
	scanf("%s" , array[stucount].name);
	printf("\n 学生ID ：");
	scanf("%d" , &(array[stucount].id));
	printf("\n 学生成绩 : ");
	scanf("%f" , &(array[stucount].score));

	stucount ++ ;
	getchar();		//清掉输入缓冲区；		
	fflush(NULL);
}

/**********************************************************************************
 * 打印信息的函数
 **********************************************************************************/
void stu_show(void)
{
	system("clear");
	printf("							学生信息打印\n");

	printf("\033[2;5HID:");
	printf("\033[2;25H 姓名：");
	printf("\033[2;45H 分数：");
	fflush(stdout);

	int i ;
	for( i = 0 ; i < stucount ; i++ )
	{
			printf("\033[%d;5H%2d" , i+4 , array[i].id);
			printf("\033[%d;25H%s" , i+4 , array[i].name);
			printf("\033[%d;45H%f" , i+4 , array[i].score);
	}
	fflush(stdout);

	printf("\033[25;0HPlease press any key to continue ...\n");
	system("stty - icanon");
	getchar();		//阻塞；
	system("stty icanon");
}

/**********************************************************************************
 * 按 ID 查找信息的子函数
 **********************************************************************************/
void search_id(int id)
{
	system("clear");
	printf("								学生信息打印\n");

	printf("\033[2;5HID:");
	printf("\033[2;25H 姓名：");
	printf("\033[2;45H 分数：");
	fflush(stdout);

	int i , j ;
	for( i = 0 , j = 0 ; i < stucount ; i++ )
	{
			if(array[i].id == id)
			{
				printf("\033[%d;5H%2d" , j+4 , array[i].id);
				printf("\033[%d;25H%s" , j+4 , array[i].name);
				printf("\033[%d;45H%f" , j+4 , array[i].score);
				j++	;
			}
	}
	fflush(stdout);

	printf("\033[25;0HPlease press any key to continue ...\n");
	system("stty - icanon");
	getchar();		//阻塞；
	system("stty icanon");
}

/**********************************************************************************
 * 按名称查找信息的子函数
 **********************************************************************************/
void search_name(const char * name)
{
		system("clear");
	printf("								学生信息打印\n");

	printf("\033[2;5HID:");
	printf("\033[2;25H 姓名：");
	printf("\033[2;45H 分数：");
	fflush(stdout);

	int i , j ;
	for( i = 0 , j = 0 ; i < stucount ; i++ )
	{
			if(strcmp(array[i].name , name) == 0)
			{
				printf("\033[%d;5H%2d" , j+4 , array[i].id);
				printf("\033[%d;25H%s" , j+4 , array[i].name);
				printf("\033[%d;45H%f" , j+4 , array[i].score);
				j++	;
			}
	}
	fflush(stdout);

	printf("\033[25;0HPlease press any key to continue ...\n");
	system("stty - icanon");
	getchar();		//阻塞；
	system("stty icanon");
}

/**********************************************************************************
 * 查找信息的函数
 **********************************************************************************/
void stu_search(void)
{
	char ch ;
	int id ;
	char name[30];
repeat:
	system("clear");
	printf("								学生信息查找\n");

	printf("请选择按什么方式查找学生信息：\n");

	printf("						1.ID \n");
	printf("						2.NAME \n");
	fflush(stdout);

	system("stty - icanon");
	ch = getchar();		//阻塞；
	system("stty icanon");

	if(ch == '1')
	{
			printf("请输入学生ID：");
			fflush(stdout);
			scanf("%d" , &id);
			getchar();
			if(id < 0)
			{
				getchar();
				printf("输入ID有误，请按任意键重新选择输入\n");
				system("stty - icanon");
				getchar();		//阻塞；
				system("stty icanon");
				goto repeat;
			}
			search_id(id);
	}
	if(ch == '2')
	{
		printf("请输入学生姓名：");
		fflush(stdout);
		scanf("%s" , name);
		getchar();
		search_name(name);
	}
	if(ch != '1' && ch != '2')
	{
		goto repeat;
	}
}

/**********************************************************************************
 * 保存信息的函数
 **********************************************************************************/
void stu_save(void)
{
	FILE	*filp = NULL ;
	char ch ;
	char Path[30];
repeat1:
	system("clear");
	printf("							学生信息保存\n");

	printf("请选择按什么方式保存信息：\n");
	printf("							1.追加 \n");
	printf("							1.覆盖 \n");
	fflush(stdout);

	system("stty - icanon");
	ch = getchar();		//阻塞；
	system("stty icanon");

	printf("\n\n\n 请输入保存文件名：\n");
	scanf("%s" , Path);

	getchar();

	if(ch == '1')
	{
		filp = fopen(Path , "a+");
		if(NULL == filp)
		{
			fprintf(stderr , "文件打开失败 \n");
			printf("请按任意键重新选择输入 \n");
			system("stty - icanon");
			ch = getchar();		//阻塞；
			system("stty icanon");
			goto repeat1;
		}
	}
	if(ch == '2')
	{
		filp = fopen(Path , "w+");
		if(NULL == filp)
		{
			fprintf(stderr , "文件打开失败 \n");
			printf("请按任意键重新选择输入 \n");
			system("stty - icanon");
			ch = getchar();		//阻塞；
			system("stty icanon");
			goto repeat1;
		}
	}
	if(ch != '1' && ch != '2')
	{
			goto repeat1;
	}

	//文件打开成功，将信息保存至文件明文；
# if 0
		//明文
		char buffer[1024] ;
		int i ;
		for(i=0 ; i<stucount ; i++)
		{
			sprintf(buffer , "%d:%s  %f \n" , array[i].id , array[i].name , array[i].score);
			fprintf(filp , "%s" , buffer);
		}
# else 
		int i ;
		for(i=0 , i<stucount , i++);
		{
			fwrite(&(array[i]) , sizeof(struct student) , 1 , filp);
		}
# endif
		fclose(filp);
		printf("学生信息保存完毕\n");
		sleep(1);
}

/**********************************************************************************
 * 加载信息的函数
 **********************************************************************************/
void stu_load(void)
{
	FILE * filp = NULL ；
	char Path[30] ;
	system("clear");
	printf("							学生信息加载\n");
	printf("请输入导入文件名 : \n");
	scanf("%s" , Path);
	getchar();

	int i ;
	filp = fopen(Path , "r");
	if(NULL == filp)
	{
			fprintf(stderr , "文件打开失败 \n");
			printf("请按任意键退出 \n");
			system("stty - icanon");
			ch = getchar();		//阻塞；
			system("stty icanon");		
	}

	char buffer[1024] ;
	char * p = NULL ;
	int ret ;
	while(1)
	{
		ret = fread(&(array[stucount]) , sizeof(struct student) , 1 , filp);
		if(ret != 1)
				break;
		stucount++ ;
	}
	fclose(filp);
	printf("信息导入完毕\n");
	sleep(1);
}

/**********************************************************************************
 * 修改信息的函数
 **********************************************************************************/
void stu_modefi(void)
{
	int id ;
	system("clear");
	printf("							信息修改\n");

	printf("							1.ID: \n");
	fflush(stdout);
	scanf("%d" , &id);

	int i ;
	for(i=0 ; i<stucount ; i++);
	{
			if(array[i].id == id)
			{
					printf("学生姓名 ：");
					scanf("%s" , array[stucount].name);
					printf("\n 学生ID ：");
					scanf("%d" , &(array[stucount].id));
					printf("\n 学生成绩 : ");
					scanf("%f" , &(array[stucount].score));
					break ;		
			}
	}	
	getchar();
}

/**********************************************************************************
 * 删除信息的函数
 **********************************************************************************/
void stu_delete(void)
{
	char ch ;
	int id ;
	char name[30] ;

repeat3:
	system("clear");
	
}

