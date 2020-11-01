/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 8_template.cpp
 *     FIRST CREATION DATE    : 2020/11/01
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/11/01
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>

using namespace std;

template <typename T> T Add2Value(T a, T b)
{
	T result;// 定义返回类型
	result = a + b;// 计算两个数之和
	return (result);// 返回两个数之和的计算结果
}

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int i = 11, j = 222, k;
	float l = 2.718, m = 3.1415, n;

	k = Add2Value(i, j);
	n = Add2Value(l, m);

	cout << k << endl;
	cout << n << endl;

    return 0;
}

