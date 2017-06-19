#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	int i;
	char array[]="Hi,bro";

	printf("&array : %p\n",&array);

	for(i=0; i<100; i++)
	{
		sleep(1);
	}
	return 0;
}
