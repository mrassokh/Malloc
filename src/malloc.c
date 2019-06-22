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


t_block 					*get_block(void *ptr)
{
	//printf("get_block for %p, BLOCK_SIZE = %lu, result = %p",ptr, BLOCK_SIZE, ptr - BLOCK_SIZE);
	return (ptr - BLOCK_SIZE);
	//return ((t_block  *)ptr - 1);
}

int 					valid_addr(void *ptr)
{
	t_block *begin;


	begin = *memory_begin();

	if (begin)
	{
		struct rlimit rlim;
		getrlimit(RLIMIT_AS, &rlim);

		if (ptr > (void *)(begin + 1) && ptr <= (void *)(*memory_end() + 1))//9223372036854775807 - BLOCK_SIZE)//(size_t)rlim.rlim_cur)
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
			(*memory_begin()) = NULL;
			(*memory_end()) = NULL;
			munmap(memory, memory->size);
		}
		//munmap(memory, memory->size);
	}


}

void 		print_segment_header(t_block *cursor)
{
	char 		*address_str;

	if (cursor == *tiny_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("TINY : 0x");
		ft_putendl(address_str);
		free(address_str);
	}
	if (cursor == *small_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("SMALL : 0x");
		ft_putendl(address_str);
		free(address_str);
	}
	if (cursor == *large_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("LARGE : 0x");
		ft_putendl(address_str);
		free(address_str);
	}

}

void 		print_block_info(t_block *cursor)
{
	char 		*address_str;
	char 		*size;
	uint64_t	address;

	address = (uint64_t)cursor + BLOCK_SIZE;
	size = ft_itoa_base((uint64_t)(cursor->size), 10, 1);
	address_str = ft_itoa_base(address, 16, 1);

	ft_putstr("0x");
	ft_putstr(address_str);
	ft_putstr(" - ");
	free(address_str);
	address += (uint64_t)(cursor->size);
	address_str = ft_itoa_base(address, 16, 1);
	ft_putstr("0x");
	ft_putstr(address_str);
	free(address_str);
	ft_putstr(" : ");
	//printf(" %s", size);
	ft_putstr(size);
	free(size);
	ft_putendl(" bytes");
}

void 					show_alloc_mem()
{
	t_block *cursor;

	ft_putendl("memory list!!!");
	//slast_block = NULL;
	cursor = *memory_begin();
	if (!cursor)
		ft_putendl("empty memory list!!!");
	while (cursor)
	{
		print_segment_header(cursor);

		if (!cursor->is_free && cursor->size){
		print_block_info(cursor);
	}
		//ft_putendl("AAA");
		//ft_putendl(address);
		//if (i > 140)
			//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", cursor, (int)cursor->size, cursor->is_free, cursor->next, cursor->prev, *(char*)(cursor + BLOCK_SIZE),cursor->magic);
		cursor = cursor->next;

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
	//printf("last_block small_zone start = %p, \n", (char *)(*last_block));
	alloc_memory = add_new_memory_block(align8(MAX_SMALL_BLOCK_SIZE),
											*last_block);
	*last_block = alloc_memory;
	*small_segment() = *last_block;
	//alloc_memory->is_free = 1;
	alloc_memory->magic = 456;
	while (i++ < SMALL_NUM - 1)
	{
		alloc_memory = memory_allocate(align8(MAX_SMALL_BLOCK_SIZE),
		 										*last_block);
		*last_block = alloc_memory;
		//alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
	}
	ft_putstr("fill_small_zone\n\n\n\n\n");
	/*if (!(*large_segment()))
	{
		//(*large_segment()) = alloc_memory;
	}*/
	//show_alloc_mem();
	//*large_segment() = (*last_block)->next;
	//printf("last_block small_zone end = %p, \n", (char *)(*last_block));
	//show_alloc_mem();
}

void 			split_new_memory(t_block *memory, size_t used_size,t_block **last_block)
{
	ft_putstr("split_new_memory!\n");
	if (used_size +  align8(BLOCK_SIZE) > (size_t)PAGE_SIZE || !memory)
		return;
		ft_putstr("split_free_block_0!\n");
	split_free_block(memory,align8(MAX_TINY_BLOCK_SIZE));
		ft_putstr("split_free_block_1!\n");
	used_size += align8(MAX_TINY_BLOCK_SIZE) + align8(BLOCK_SIZE);
	memory = memory->next;
	*last_block = memory;
	split_new_memory(memory, used_size, last_block);
	ft_putstr("split_new_memory_end!\n");

	/*while (used_size +  align8(BLOCK_SIZE) < (size_t)PAGE_SIZE)
	{
		ft_putstr("alloc_memory_1_1\n");
		split_free_page(memory, memory->size);
		used_size += align8(memory->size) + align8(BLOCK_SIZE);
		ft_putstr("alloc_memory_1_2\n");
		if (!memory)
			break;
		memory = memory->next;

		ft_putstr("alloc_memory_1_3\n");
	}
	*last_block = memory;*/
}

void 	fill_tiny_zone_1(t_block **last_block)
{
	int 		i;
	size_t 		used_size;
	t_block 	*alloc_memory;

	i = 0;
	while (i++ < TINY_ZONE_MULT)
	{
		//ft_putstr("alloc_memory\n");
		alloc_memory = add_new_memory_block(align8(MAX_TINY_BLOCK_SIZE),
		 										*last_block);
		alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
		used_size = align8(MAX_TINY_BLOCK_SIZE) + align8(BLOCK_SIZE);
		//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", alloc_memory, (int)alloc_memory->size, alloc_memory->is_free, alloc_memory->next, alloc_memory->prev, *(char*)(alloc_memory + BLOCK_SIZE),alloc_memory->magic);
		if ((getpagesize() - alloc_memory->size) > BLOCK_SIZE + 8)// && memory->magic == 123)
		{
			ft_putstr("split_free_page!\n");
			split_free_page(alloc_memory, alloc_memory->size);
			//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", alloc_memory, (int)alloc_memory->size, alloc_memory->is_free, alloc_memory->next, alloc_memory->prev, *(char*)(alloc_memory + BLOCK_SIZE),alloc_memory->magic);
			alloc_memory = alloc_memory->next;
			*memory_end() = alloc_memory;
			//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", alloc_memory, (int)alloc_memory->size, alloc_memory->is_free, alloc_memory->next, alloc_memory->prev, *(char*)(alloc_memory + BLOCK_SIZE),alloc_memory->magic);
			//*last_block = alloc_memory;
			while ((PAGE_SIZE - used_size) > align8(MAX_TINY_BLOCK_SIZE) + BLOCK_SIZE + 8)
			{
				ft_putstr("split_free_block!\n");
				//break;
				split_free_block(alloc_memory, align8(MAX_TINY_BLOCK_SIZE));
				used_size += align8(MAX_TINY_BLOCK_SIZE) + BLOCK_SIZE;
				alloc_memory = alloc_memory->next;
				//*last_block = alloc_memory;
				*memory_end() = alloc_memory;
				//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", alloc_memory, (int)alloc_memory->size, alloc_memory->is_free, alloc_memory->next, alloc_memory->prev, *(char*)(alloc_memory + BLOCK_SIZE),alloc_memory->magic);
				//printf(" address = %p; size = %d; is free = %d; cursor->next = %p; cursor->prev = %p, i = %d, magic = %d\n", alloc_memory, (int)alloc_memory->size, alloc_memory->is_free, alloc_memory->next, alloc_memory->prev, *(char*)(alloc_memory + BLOCK_SIZE),alloc_memory->magic);
			}
			//split_new_memory(alloc_memory, used_size, last_block);
			//memory->is_free = 0;
		}
		//split_new_memory(alloc_memory, used_size, last_block);
		/*alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
				//ft_putstr("alloc_memory_1\n");
		while ((PAGE_SIZE - alloc_memory->size) > BLOCK_SIZE + 8)
		{
							//ft_putstr("alloc_memory_1_1\n");
			split_free_page(alloc_memory, alloc_memory->size);
			//ft_putstr("alloc_memory_1_2\n");
			alloc_memory = alloc_memory->next;
			//ft_putstr("alloc_memory_1_3\n");
		}*/
	}
	ft_putstr("fill_tiny_zone\n\n\n\n\n");
	*tiny_segment() = *memory_begin();
	//*last_block = *memory_list_end();
	//printf("begin tiny segment = %p, \n", (char *)(*tiny_segment()) + BLOCK_SIZE);
	//ft_putstr("fill_tiny_zone\n\n\n\n\n");
	//show_alloc_mem();
	//printf("last_block tiny segment = %p, \n", (char *)(*last_block));
}



void 	fill_tiny_zone(t_block **last_block)
{
	int 		i;
	t_block 	*alloc_memory;

	i = 0;

	while (i++ < TINY_NUM)
	{
		//alloc_memory = add_new_memory_block(align8(MAX_TINY_BLOCK_SIZE),
		 										//*last_block);
		alloc_memory = memory_allocate(align8(MAX_TINY_BLOCK_SIZE),*last_block);
		*last_block = alloc_memory;
		/*while ((getpagesize() - alloc_memory->size) > BLOCK_SIZE + 8 && memory->magic == 123
			&& i++ < TINY_NUM)
		{
			split_free_page(memory, memory->size);
		}*/
		//alloc_memory->is_free = 1;
		alloc_memory->magic = 456;
	}
	ft_putstr("fill_tiny_zone\n\n\n\n\n");
	*tiny_segment() = *memory_begin();
	t_block * cursor = *tiny_segment();
	while (cursor && cursor->magic == 456)
	{
		//cursor->is_free = 1;
		/*if (cursor->magic == 456)
			cursor->is_free = 1;*/
			cursor = cursor->next;

	}
	//*last_block = *memory_list_end();
	//printf("begin tiny segment = %p, \n", (char *)(*tiny_segment()) + BLOCK_SIZE);
	//ft_putstr("fill_tiny_zone\n\n\n\n\n");
	//show_alloc_mem();
	//printf("last_block tiny segment = %p, \n", (char *)(*last_block));
}

void 					first_call_processing()
{
	ft_putstr("FIRST CALL\n\n\n\n\n");
	*is_not_first_call() = 1;
	//t_block * cursor;

	//last_block = *memory_list();
	fill_tiny_zone(memory_end());
	  fill_small_zone(memory_end());

	//t_block * cursor = *tiny_segment();
	//while (cursor && cursor->magic == 456)
	//{
		//cursor->is_free = 1;
		/*if (cursor->magic == 456)
			cursor->is_free = 1;*/
		//cursor = cursor->next;
	//}
	//show_alloc_mem();
	//*tiny_segment() =
	//is_not_first_call = 1;
}
//void 	*malloc_1(size_t size)
t_block  *memory_allocate(size_t size, t_block *last_block)//, int preallocate)
{
	t_block *memory;

	memory = find_free_block(size, &last_block);//, preallocate);

//	ft_putstr("find_free_block_finish\n");
	if (!memory) {
		//ft_putstr("add_new_memory_block!\n");
		memory = add_new_memory_block(size, last_block);
		if (!memory)
			return NULL;
		/*if (!(*large_segment()) &&  memory->size > MAX_SMALL_BLOCK_SIZE)
		{
			(*large_segment()) = memory;
		}*/
		if ((getpagesize() - memory->size) > BLOCK_SIZE + 8)// && memory->magic == 123)
		{
			//	ft_putstr("split_free_page!\n");
			split_free_page(memory, memory->size);
			memory->is_free = 0;
		}
	}
	else {
		if ((memory->size - size) > BLOCK_SIZE + 8 && memory->magic == 123)
		{
		//	ft_putstr("split_free_block!\n");
			split_free_block(memory, size);

		}
		memory->is_free = 0;
		//memory->magic = 123;
	}
	return memory;
}

void 	*malloc(size_t size)
{
	if (size == 0)
		return NULL;
	size_t size_allign = align8(size);
	t_block *memory;
	t_block * last_block;
	t_block *begin;

	//ft_putstr("start_malloc\n");
	begin = *memory_begin();
	last_block = begin;
	if (!begin)
	{
		first_call_processing();
	}
	//ft_putstr("finall_fcp");
	memory = memory_allocate(size_allign, last_block);
	//if (!(*large_segment()) &&  memory->magic == 123)
	if (!(*large_segment()) &&  memory->magic == 123)
	{
		(*large_segment()) = memory;
	}

	//if (*large_segment())
	if (memory->magic == 123)
	{
		(memory_list()->count)++;
		if (memory_list()->count > 450){
			t_block * cursor = *tiny_segment();
			while (cursor && cursor->magic == 456)
			{
				cursor->is_free = 1;
				cursor = cursor->next;

			}
			memory_list()->count = -1;
			//*large_segment() = memory;
		}
	}

	/*t_block * cursor = *tiny_segment();
	while (cursor && cursor->magic == 456)
	{
		cursor->is_free = 1;
		if (cursor->magic == 456)
			cursor->is_free = 1;
		cursor = cursor->next;
	}*/
	//memory = find_free_block(size, &last_block);
	/*if (!memory){
		memory = memory_allocate(size_allign, last_block);
	} else {
		if ((memory->size - size) > BLOCK_SIZE + 8 && memory->magic == 123)
		{
			split_free_block(memory, size);
		}
		memory->is_free = 0;
		//memory->magic = 123;
	}*/

	return MEMORY_DATA(memory);//memory ? memory + BLOCK_SIZE : NULL;//MEMORY_DATA(memory);
}

/*void 	*malloc(size_t size)
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
}*/
