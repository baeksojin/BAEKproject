#include <stdio.h>
#include <stdlib.h>
#include <unist.h>

int main(void)
{
	void *p;
	
	while(1)
	{
		write(1, "BEFORE MALLOC #0\n", 17);
		p= malloc(512);
		write(1, "AFTER MALLOC #0\n",16);
		printf("%p\n",p);
	}
	getchar();
	return (EXIT_SUCCESS);
}
	
