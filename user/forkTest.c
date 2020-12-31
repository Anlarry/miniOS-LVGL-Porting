
/*======================================================================*
                          Syscall Fork Test
added by xw, 18/4/27
 *======================================================================*/
#include "stdio.h"
int global=0;
int var = 0;

void main(int arg,char *argv[])
{
	int i=0;
	
	//i = get_pid();

	printf("Hello world!\n");
	 //deleted by mingxuan 2019-5-23
	int pid = fork();
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100000; j++) 
			for(int k = 0; k < 1000; k++)  ;
		printf("%d ", var++);
	}
	

	return ;
}