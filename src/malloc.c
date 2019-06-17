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
	//printf("get_block for %p, BLOCK_SIZE = %lu, result = %p",ptr, BLOCK_SIZE, ptr - BLOCK_SIZE);
	return (ptr - BLOCK_SIZE);
	//return ((t_block  *)ptr - 1);
}

int 					valid_addr(void *ptr)
{
	t_block *begin;


	begin = *memory_list();

	if (begin)
	{
		struct rlimit rlim;
		getrlimit(RLIMIT_AS, &rlim);

		if (ptr > (void *)(begin + 1) && ptr <= (void *)(*memory_list_end() + 1))//9223372036854775807 - BLOCK_SIZE)//(size_t)rlim.rlim_cur)
		{
			//ft_putstr("VALID POINTER!!!\n");
			return (ptr == GET_BLOCK_POINTER(ptr) + BLOCK_SIZE);
		}
	}
	return 0;
}

//void					free_1(void *ptr)
void					free(void *ptr)
{
	t_block *memory;
	//ft_putstr("get memory for free\n");
	memory = GET_BLOCK_POINTER(ptr);//get_block(ptr);
	//ft_putstr("try free\n");
	if (!valid_addr(ptr))// || memory->magic != 123)
	{
		//ft_putendl("not valid pointer\n");
		return;
	}
	/*if (!memory)
		return;
	if (memory < 0)
	{
		ft_putendl("not valid pointer\n");
		return;
	}*/
	//ft_putstr("print memory\n");
	//ft_putendl((char*)memory);
	//ft_putendl((char*)ptr);
	//ft_putstr("print memory finish\n");
	if (memory->is_free)
	{
		ft_putstr("memory is already free\n");
		return;
	}
	if (memory->magic != 123 && memory->magic != 456) {
		ft_putstr("invalid pointer for free\n");
		return;
	}
	//ft_putstr("free\n");
	//printf("free %p for %p, BLOCK_SIZE = %lu",ptr, memory, BLOCK_SIZE);
	//printf("address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", memory, (int)memory->size, memory->is_free, memory->next, memory->prev, *(char*)(memory + BLOCK_SIZE), memory->magic);
	memory->is_free = 1;
	if (memory->prev && memory->prev->is_free && memory->magic != 456)
	{
		ft_putstr("memory->prev && memory->prev->is_free\n");
		memory = memory_fusion(memory->prev);
	}
	if (memory->next){
		//ft_putstr("memory->next\n");
		//if (memory->magic != 456)
			memory_fusion(memory);
	}
	else
	{
		ft_putstr("free next null\n");
		if (memory->prev){
			//ft_putstr("memory->prev\n");
			//(*memory_list_end()) = memory->prev;
			//memory->prev->next = NULL;
			//ft_putstr("memory->prev_finish\n");
		}
		else {
			ft_putstr("memory->prev = null\n");
			(*memory_list()) = NULL;
			(*memory_list_end()) = NULL;
			munmap(memory, memory->size);
		}
		//munmap(memory, memory->size);
	}


}
void 					show_alloc_mem()
{
	t_block *cursor;
	char 	*address;

	//slast_block = NULL;
	cursor = *memory_list();
	//ft_putstr("Hello_show!\n");
	if (!cursor)
		ft_putendl("empty list!!!");
	//int i = 0;
	while (cursor)
	{
		address = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("0x");
		ft_putendl(address);
		free(address);
		//ft_putendl("AAA");
		//ft_putendl(address);
		//if (i > 140)
			//printf("iteration = %d; address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", i, cursor, (int)cursor->size, cursor->is_free, cursor->next, cursor->prev, *(char*)(cursor + BLOCK_SIZE),cursor->magic);
		cursor = cursor->next;
		//i++;

		//ft_putstr("0x");
	}
	//printf("begin + BLOCK_SIZE = %p, *memory_list_end() + BLOCK_SIZE = %p\n", (char *)(*memory_list()) + BLOCK_SIZE, (char *)(*memory_list_end()) + BLOCK_SIZE);
}

/*void					*realloc(void *ptr, size_t size)
{
	rea
}*/
void					*calloc(size_t nitems, size_t size)
{
	//printf("call calloc with %lu and %lu", nitems, size);
	//ft_putstr("calloc\n");
	size_t *ptr = malloc(nitems * size);
	if (ptr) {
		size_t s4 = align8(nitems * size);//<< 2;
		while (s4--)
		{
			ptr[s4] = 0;
		}
	}
		/*for (i=0; i<s4 ; i++)
		{
			new[i] = 0;
		}*/

	return ptr;//malloc(nitems * size);
}
int* is_not_first_call() {
static int is_not_first_call;
return (&is_not_first_call);
}

void 	fill_small_zone(t_block **last_block)
{
	int 		i;
	t_block 	*alloc_memory;

	i = 0;
	printf("last_block small_zone start = %p, \n", (char *)(*last_block));
	alloc_memory = add_new_memory_block(align8(MAX_SMALL_BLOCK_SIZE),
											*last_block);
	*last_block = alloc_memory;
	*small_segment() = *last_block;
	alloc_memory->is_free = 1;
	alloc_memory->magic = 456;
	while (i++ < SMALL_NUM - 1)
	{
		alloc_memory = add_new_memory_block(align8(MAX_SMALL_BLOCK_SIZE),
		 										*last_block);
		*last_block = alloc_memory;
		alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
	}
	ft_putstr("fill_small_zone\n\n\n\n\n");
	//show_alloc_mem();

	printf("last_block small_zone end = %p, \n", (char *)(*last_block));
//	show_alloc_mem();
}

void 	fill_tiny_zone(t_block **last_block)
{
	int 		i;
	t_block 	*alloc_memory;

	i = 0;

	while (i++ < TINY_NUM)
	{
		alloc_memory = add_new_memory_block(align8(MAX_TINY_BLOCK_SIZE),
		 										*last_block);
		*last_block = alloc_memory;
		alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
	}
	*tiny_segment() = *memory_list();
	//*last_block = *memory_list_end();
	printf("begin tiny segment = %p, \n", (char *)(*tiny_segment()) + BLOCK_SIZE);
	ft_putstr("fill_tiny_zone\n\n\n\n\n");
	//show_alloc_mem();
	printf("last_block tiny segment = %p, \n", (char *)(*last_block));
}

void 					first_call_processing()
{
	ft_putstr("FIRST CALL\n\n\n\n\n");
	*is_not_first_call() = 1;
	//t_block * last_block;

	//last_block = *memory_list();
	fill_tiny_zone(memory_list_end());
	fill_small_zone(memory_list_end());
	//*tiny_segment() =
	//is_not_first_call = 1;
}
//void 	*malloc_1(size_t size)
void 	*malloc(size_t size)
{
	if (size == 0)
		return NULL;
	size_t size_allign = align8(size);
	//if (!*tiny_segment() && !*small_segment())
	if (!(*is_not_first_call()))
		first_call_processing();
	t_block *memory;
	t_block * last_block;
	t_block *begin;

	//ft_putstr("start_malloc\n");
	begin = *memory_list();
	last_block = begin;
	if (begin) {

		//ft_putstr("find_free_block\n");
		//show_alloc_mem();
		memory = find_free_block(size_allign, &last_block);

	//	ft_putstr("find_free_block_finish\n");
		if (!memory) {
			//ft_putstr("add_new_memory_block!\n");
			memory = add_new_memory_block(size_allign, last_block);
			if (!memory)
				return NULL;
				if ((getpagesize() - memory->size) > BLOCK_SIZE + 8 && memory->magic == 123)
				{
					//ft_putstr("split_free_page!\n");
					split_free_page(memory, memory->size);
					memory->is_free = 0;
				}
		} else {
			if ((memory->size - size_allign) > BLOCK_SIZE + 8 && memory->magic == 123)
			{
			//	ft_putstr("split_free_block!\n");
				split_free_block(memory, size_allign);

			}
			memory->is_free = 0;
			//memory->magic = 123;
		}
	} else {
		//ft_putstr("start\n");
		memory = add_new_memory_block(size_allign, last_block);
		//ft_putstr((char*)memory);
		//ft_itoa_base((uint64_t)memory, 16, 1);
		//ft_putstr("start_1\n");
		if (!memory)
			return NULL;
		//ft_putstr("start_2\n");
		last_block = memory;
		//ft_putstr("start_3\n");
	}

	return MEMORY_DATA(memory);//memory ? memory + BLOCK_SIZE : NULL;//MEMORY_DATA(memory);
}
