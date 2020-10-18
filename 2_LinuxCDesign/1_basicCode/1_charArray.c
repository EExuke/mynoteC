/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 1_charArray.c
 *     FIRST CREATION DATE    : 2020/10/18
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/18
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	int a[10];
	int i, j;
	int t;

	printf("排序前的数组：\n");
	for (i=0; i<10; i++) {
		a[i] = rand() % 100 + 1;
		printf("%4d", a[i]);
	}
	printf("排序后的数组：\n");
	for (i=0; i<9; i++) {
		for (j=i+1; j<10; j++) {
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i=0; i<10; i++) {
		printf("%4d ", a[i]);
	}

    return 0;
}

