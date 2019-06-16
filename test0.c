//#include "includes/malloc.h"
#include <stdio.h>
#include <sys/resource.h>

typedef struct			s_block
{
	int					is_free;
	//int				size;
	size_t				size;

	struct s_block		*next;
	/*struct s_block		*prev;
	int 				magic;*/
	//struct s_block		*this;
	//char 				data [1];
}						t_block;

int main()
{
	int i  = 10;
	int *pi = &i;
	char *addr;
	t_block block;
	size_t				size;

	struct rlimit rlim;
	getrlimit(RLIMIT_AS, &rlim);

	printf("rlim.rlim_cur = %lu; rlim.rlim_max = %lu", (size_t)rlim.rlim_cur, (size_t)rlim.rlim_max );

	printf("sizeof int = %lu, sizeof *int = %lu, sizeof *addr = %lu\n", sizeof(i), sizeof(pi),sizeof(addr));
	printf("sizeof is_free = %lu; sizeof size = %lu ;sizeof  next = %lu; t_block = %lu", sizeof(block.is_free), sizeof(block.size), sizeof(block.next),sizeof(block));
	/*i = 0;
	while (i < 1024)
	{
		i++;
	}*/
	return (0);
}
