/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 3_playList.c
 *     FIRST CREATION DATE    : 2020/10/18
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/18
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define GET_NAME    "%255s"
#define MAX_LENGTH    40
#define MAX_FILE_LENGTH    255

int main()
{
	unsigned int i, l;
	char *p_list[MAX_LENGTH];
	char f_list[MAX_LENGTH][MAX_FILE_LENGTH + 1];
	int select_value;
	char exit_switch = 1;

	for (i=0; i<MAX_LENGTH; i++) {
		p_list[i] = NULL;
		f_list[i][0] = 0;
	}

	l = 0;
	do {
		puts("请选择操作命令：");
		puts("(1)添加新文件");
		puts("(2)删除列表中的文件");
		puts("(3)打印播放列表");
		puts("(4)退出程序");
		scanf("%1d", &select_value);// 输入的菜单选择
		getchar();// 吸收多余的输入字符
		switch (select_value) {
			case 1:
				if (l < MAX_LENGTH) {
					puts("请输入文件名：");
					for (i=0; i<MAX_LENGTH; i++) {
						if (!f_list[i][0]) {
							while (!scanf(GET_NAME, f_list[i])) {
								puts("请输入正确的文件名!");
							}
							p_list[l++] = f_list[i];    //将指针列表所对应的单元指向文件名存放的内存地址
							break;
						}
					}
				} else {
					puts("文件列表已满!");
				}
				break;
			case 2:
				puts("请输入文件编号: ");
				scanf("%u", &i);
				if (i > 0 && i <= l) {
					*p_list[--i] = NULL;
					while(i < l - 1) {
						p_list[i] = p_list[i + 1];
						i++;
					}
					l--;
				} else {
					puts("您所输入的文件编号不存在！");
					break;
				}
			case 3:
				for (i=0; i<l; i++) {
					printf("%d: %s\n", i+1, p_list[i]);    //通过指针列表间接引用文件名列表，输出文件名
				}
				break;
			case 4:
				exit_switch = 0;
		}
	} while (exit_switch);
	return 0;
}
