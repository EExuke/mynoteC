/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 1_openFile.cpp
 *     FIRST CREATION DATE    : 2020/11/01
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/11/01
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>// 提供open()函数
#include <sys/types.h>// 提供mode_t类型
#include <sys/stat.h>// 提供open()函数的符号
#include <unistd.h>// 提供close()函数

using namespace std;
/****************************************************************************
 *  Function Name : main
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int f;
	const char *f_path = "test";
	mode_t f_attrib;
	f_attrib = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	f = open(f_path, O_RDONLY);
	if (f == -1) {
		f = open(f_path, O_RDWR | O_CREAT, f_attrib);
		if (f != -1) {
			puts("创建一个文件");
		} else {
			puts("无法创建新文件，程序退出");
			return 1;
		}
	} else {
		puts("文件打开成功");
	}
	close(f);
    return 0;
}

