/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 7_inheritance.cpp
 *     FIRST CREATION DATE    : 2020/11/01
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/11/01
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>

using namespace std;

Class Cstd { // 定义父类Cstd
	public:
		void set_values (int a, int b) { width=a; height=b;}
	protected:
		int width;// 图形的底
		int height;// 图形的高
};

class Crect: public Cstd// 定义子类Crect
{
	public:
		int area (void) {
			return (width * height); 
		}
		// 定义子类成员函数，用于计算矩形面积
};

class Cdelt: public Cstd// 定义子类Cdelt
{
	public:
		int area (void) {
			return (width * height / 2); 
		}
		// 定义子类成员函数，用于计算三角形面积
};

/****************************************************************************
 *  Function Name : main
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	Crect rect;
	Cdelt delt;
	rect.set_values(4, 5);
	delt.set_values(4, 5);

	cout << rect.area() << endl;
	cout << delt.area() << endl;
    return 0;
}

