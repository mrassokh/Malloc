#include "includes/malloc.h"
//#include <stdio.h>
int main()
{
	int i;
	char *addr[10];

	i = 0;
	ft_putstr("Hello\n");
	addr[0] = (char*)malloc(1024);
	show_alloc_mem();
	addr[1] = (char*)malloc(30);
	show_alloc_mem();
		addr[2] = (char*)malloc(2048);
	show_alloc_mem();
	ft_putstr("Try free \n");
	free(addr[0]);
	show_alloc_mem();
		ft_putstr("Try free 1\n");
	free(addr[1]);
	show_alloc_mem();
	free(addr[2]);
	show_alloc_mem();
	ft_putstr("By\n");
	/*addr[0] = (char*)malloc_1(20);
	addr[0][0] = 42;
		show_alloc_mem();
	addr[1] = (char*)malloc_1(30);
	//addr[1][0] = 42;
		show_alloc_mem();
		addr[2] = (char*)malloc_1(10);
			show_alloc_mem();
	printf("free  adress\n");
	free_1(addr[1]);
	show_alloc_mem();
	free_1(addr[0]);
	show_alloc_mem();
	addr[0][90] = 42;
	free_1(&(addr[0][90]));
	printf("new allocate adress\n");
	addr[3] = (char*)malloc_1(10);
	show_alloc_mem();
	addr[4] = (char*)malloc_1(2);
	show_alloc_mem();
	printf("free  adress\n");
	free_1(addr[0]);
	free_1(addr[4]);
	show_alloc_mem();
	addr[0] = (char*)malloc_1(10);
		show_alloc_mem();
		printf("realloc  adress\n");
		addr[5] = realloc_1(addr[0], 20);
			show_alloc_mem();
			printf("addr[5][0] = %d ", addr[5][0]);

	addr[9] = malloc(100);
	free_1(addr[9]);*/
	//free_1(addr[2]);
	//show_alloc_mem();


	//addr[0] = (char*)malloc(20);
	/*addr[0][0] = 42;
		show_alloc_mem();
	addr[1] = (char*)malloc(30);
	//addr[1][0] = 42;
		show_alloc_mem();
		addr[2] = (char*)malloc(10);
			show_alloc_mem();
	printf("free  adress\n");
	free(addr[1]);
	show_alloc_mem();
	free(addr[0]);
	show_alloc_mem();
	printf("new allocate adress\n");
	addr[3] = (char*)malloc(10);
	show_alloc_mem();
	addr[4] = (char*)malloc(2);
	show_alloc_mem();
	printf("free  adress\n");
	free(addr[0]);
	free(addr[4]);
	show_alloc_mem();
		printf("realloc  adress\n");
		addr[5] = realloc(addr[0], 10);
			show_alloc_mem();
			printf("addr[5][0] = %d ", addr[5][0]);*/
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
