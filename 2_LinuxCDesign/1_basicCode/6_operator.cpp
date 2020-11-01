/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 6_operator.cpp
 *     FIRST CREATION DATE    : 2020/11/01
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/11/01
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class String {
public:
	String (const char *str = NULL);
	char *m_data;
	char *addstr;
	String& operator + (const String& rhs);    //重载加法运算符
};
//构造函数
String::String(const char *str)
{
	if (str == NULL) {
		m_data = new char[1];
		m_data[0] = '\0';
	} else {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}
//重载加法运算符
String &String::operator+(const String& rhs)
{
	addstr = new char[strlen(m_data) + strlen(rhs.m_data) + 1];    //临时空间
	strcpy(addstr, m_data);
	strcat(addstr, rhs.m_data);
	delete [] m_data;
	m_data = new char[strlen(addstr) + 1];    //重新划分m_data空间长度
	strcpy(m_data, addstr);    //写回m_data成员位置
	delete [] addstr;
	return *this;
}

/****************************************************************************
 *  Function Name : main
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	String s1("I love ");
	String s2("you!");

	s1 + s2;
	puts(s1.m_data);
    return 0;
}

