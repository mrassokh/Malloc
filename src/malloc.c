/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:29:51 by mrassokh          #+#    #+#             */
/*   Updated: 2019/01/06 13:29:53 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

void 	hello()
{
	char a = '\n';
	write(1, &a, 1);
	//printf("Hello world!!!\n");
}

t_block 					*get_block(void *ptr)
{
	printf("get_block for %p, BLOCK_SIZE = %lu, result = %p",ptr, BLOCK_SIZE, ptr - BLOCK_SIZE);
	return (ptr - BLOCK_SIZE);
}

void					free_1(void *ptr)
{
	t_block *memory;
	memory = get_block(ptr);
	printf("free %p for %p, BLOCK_SIZE = %lu",ptr, memory, BLOCK_SIZE);
	printf("address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d\n", memory, (int)memory->size, memory->is_free, memory->next, memory->prev, *(char*)(memory + BLOCK_SIZE));
	memory->is_free = 1;
	if (memory->prev && memory->prev->is_free)
		memory = memory_fusion(memory->prev);
	if (memory->next)
		memory_fusion(memory);
	else
	{
		if (memory->prev)
			memory->prev->next = NULL;
		else
			(*memory_list()) = NULL;
		munmap(memory, memory->size);
	}


}
void 					show_alloc_mem()
{
	t_block *cursor;
	char 	*address;

	//slast_block = NULL;
	cursor = *memory_list();
	//ft_putstr("Hello_show!\n");
	int i = 0;
	while (cursor)
	{
		address = ft_itoa_base((uint64_t)cursor, 16, 1);
		//ft_putstr("0x");
		//ft_putendl(address);
		printf("iteration = %d; address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d\n", i, cursor, (int)cursor->size, cursor->is_free, cursor->next, cursor->prev, *(char*)(cursor + BLOCK_SIZE));
		cursor = cursor->next;
		i++;

		//ft_putstr("0x");
	}
}

/*void					*realloc(void *ptr, size_t size)
{
	rea
}*/
void					*calloc(size_t nitems, size_t size);

void 	*malloc_1(size_t size)
{
	if (size == 0)
		return NULL;
	size_t size_allign = align4(size);
	t_block *memory;
	t_block * last_block;
	t_block *begin;

	begin = *memory_list();
	last_block = begin;
	if (begin) {
		ft_putstr("find_free_block\n");
		memory = find_free_block(size_allign, &last_block);

		ft_putstr("find_free_block_finish\n");
		if (!memory) {
			ft_putstr("add_new_memory_block!\n");
			memory = add_new_memory_block(size_allign, last_block);
			if (!memory)
				return NULL;
		} else {
			if ((memory->size - size) >= BLOCK_SIZE + 4)
			{
				split_free_block(memory, size);

			}
			memory->is_free = 0;
		}
	} else {
		memory = add_new_memory_block(size_allign, last_block);
		if (!memory)
			return NULL;
		last_block = memory;
	}
	//ft_putstr("show_alloc_mem() in malloc finish\n");
	//show_alloc_mem();
	// char 	*address;
	// address = ft_itoa_base((uint64_t)memory, 16, 1);
	// ft_putstr("0x");
	// ft_putendl(address);
	//split_free_block(memory, size);
	//if ((uint64_t)MEMORY_DATA(memory) == 0)
	//	ft_putstr("FUCK!!!");
		ft_putstr("Before finish!\n");
	//	ft_putstr("0x");
		//ft_putendl(ft_itoa_base((uint64_t)MEMORY_DATA(memory), 16, 1));
	return MEMORY_DATA(memory);//memory ? memory + BLOCK_SIZE : NULL;//MEMORY_DATA(memory);
}
