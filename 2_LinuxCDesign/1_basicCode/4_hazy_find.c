/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : 4_hazy_find.c
 *     FIRST CREATION DATE    : 2020/10/18
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/18
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int hazy_find()
{
	const char *ct = "*?";    //通配符
	int i, j, l;
	char sec[MAX_FILE_LENGTH];
	int res;
	const char *res2;

	l = strlen(str2);
	if (l < 1) {
		return 0;
	}
	for (i=0; i<l; i++) {
		if (str2[i] == '?') {
			j++;
		} else if (str2[i] == '*') {
			while (!(k = strcspn(str2 + i + 1, ct))) {
				if (*(str2 + i + 1)) {
					i++;
				} else {
					return 1;
				}
			}
			strncpy(sec, str2+i+1, k);
			sec[k] = '\0';
			res2 = strstr(str1 + j, sec);
			if (!res2) {
				return 0;
			}
			i += k;
			j += strlen(str1 + j) - strlen(res2) + k;
		} else {
			k = strcspn(str2+i, ct);
			res = strncmp(str1+j, str2+i, k);
			if (res) {
				return 0;
			} else {
				i += k - 1;
				j += k;
			}
		}
		return 1;
	}
}


