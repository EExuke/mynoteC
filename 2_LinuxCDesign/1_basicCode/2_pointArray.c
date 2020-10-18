/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 2_pointArray.c
 *     FIRST CREATION DATE    : 2020/10/18
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/18
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N    4
#define M    2

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
	int a[][], *pa;
	int i, j;

	pa = a[0];
	printf("input value for array: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", pa + i*N + j);
			putchar('\0');
		}
	}
	printf("数组内的数值：");
	for (i=0; i<M*N; i++) {
		printf("%d\n", *(pa+i));
	}

    return 0;
}

