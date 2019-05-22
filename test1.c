#include "includes/malloc.h"
#include <stdio.h>
int main()
{
	int i;
	char *addr[10];

	i = 0;
	addr[0] = (char*)malloc_1(20);
		show_alloc_mem();
	addr[1] = (char*)malloc_1(30);
	addr[1][0] = 42;
		show_alloc_mem();
		addr[2] = (char*)malloc_1(10);
			show_alloc_mem();
	printf("free  adress\n");
	free_1(addr[1]);
	show_alloc_mem();
	free_1(addr[0]);
	show_alloc_mem();
	printf("new allocate adress\n");
	addr[3] = (char*)malloc_1(10);
	show_alloc_mem();
	addr[4] = (char*)malloc_1(2);
	show_alloc_mem();
	printf("free  adress\n");
	free_1(addr[0]);
	free_1(addr[4]);
	show_alloc_mem();
		printf("realloc  adress\n");
		addr[5] = realloc_1(addr[1], 100);
			show_alloc_mem();
			printf("addr[5][0] = %d ", addr[5][0]);
	//free_1(addr[2]);
	//show_alloc_mem();



	/*while (i < 3)
	{
		addr = (char*)malloc_1(1024);
		addr[0] = i;
		show_alloc_mem();
		free_1(addr);
		show_alloc_mem();
		i++;
	}*/
	return (0);
}
