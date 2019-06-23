
#include "includes/malloc.h"

int main()
{
	for (int i = 0; i < 100; ++i){
		malloc(12);
	}


	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
