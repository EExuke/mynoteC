#include <stdio.h>
#include "add.h" 	//调用静态库；
int main(void)
{
	int ret;
	ret = add(1,2);
	printf("ret:%d \n",ret);
	return 0;
}
