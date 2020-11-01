/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 5_class.cpp
 *     FIRST CREATION DATE    : 2020/11/01
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/11/01
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include <string.h>

using namespace std;

class Buddy() {
	public:
		Buddy();
		void setBuddy(const char *, long, const char *);
		void printBuddy();
	private:
		char name[50];
		long telnum;
		char address[200];
};

Buddy::Buddy()
{
	name[0] = '\0';
	telnum = -1;
	address[0] = '\0';
}

void Buddy::setBuddy(const char *n, long t, const char *a)
{
	strcpy(name, n);
	telnum = t;
	strcpy(address, a);
}

void Buddy::printBuddy()
{
	cout << "姓名：" << name << " 电话：" << telnum << " 地址：" << address << endl;
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
	Buddy b;

	b.setBuddy("xuke", 12345678901, "China");
	b.printBuddy();

    return 0;
}

