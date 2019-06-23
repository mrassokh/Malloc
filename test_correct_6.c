
#include "includes/malloc.h"

int main()
{

	char *addr = calloc(42, 1);
	for (int i = 0; i < 42; i++)
	{
		if (addr[i] == 0)
			ft_putstr("0");

	}
		ft_putstr("\n");
	//ft_putendl(addr);
	return (0);
}
