#include "includes/malloc.h"
#include <stdio.h>
int main()
{

	//printf("test1\n");
	//hello();
	// void * ptr = malloc(10);
	// if (ptr)
	// 	return 0;
	void *ptr = 0;
	if ((ptr = malloc(10)))
		printf("ptr = %d\n", (int)ptr);
	for (int i = 0; i < 10; ++i)
	{
		((int*)ptr)[i] = i;
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("ptr = %d\n", ((int*)ptr)[i]);
	}
	printf("sizeof ptr = %lu\n", sizeof(ptr));
	return 0;
}
