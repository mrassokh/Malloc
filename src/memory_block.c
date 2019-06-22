/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:21:17 by mrassokh          #+#    #+#             */
/*   Updated: 2019/01/26 12:21:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_memory 	*memory_list()
{
	static t_memory memory_list;

	return (&memory_list);
}

t_block 	**memory_begin()
{
	//static t_block *memory_list;

	return (&memory_list()->memory_begin);
}

t_block 	**tiny_segment()
{
	return (&memory_list()->tiny_segment);
	// static t_block *tiny_segment;
	//
	// return (&tiny_segment);
}

t_block 	**small_segment()
{
	return (&memory_list()->small_segment);
	/*static t_block *small_segment;

	return (&small_segment);*/
}

t_block 				**memory_end()
{
	return (&memory_list()->memory_list_end);
}

t_block 			**large_segment()
{
	return (&memory_list()->large_segment);
}
//static t_block			**mem_list;

//void					*realloc_1(void *ptr, size_t size)
void					*realloc(void *ptr, size_t size)
{
	void 		*new_ptr;
	t_block 	*curr_block;
	//t_block 	*new_block;
	size_t		alligned_size;
ft_putstr("realloc\n");
	if (!ptr)
		//return malloc_1(size);
		return malloc(size);
	if (!valid_addr(ptr))
		return NULL;
	alligned_size = align8(size);
	curr_block = GET_BLOCK_POINTER(ptr);//get_block(ptr);
		ft_putstr("realloc_in_0_0\n");
	if (curr_block->magic != 123 && curr_block->magic != 456){
				//ft_putstr("curr_block->magic != 123 || curr_block->magic != 456\n");
				//printf("curr_block->magic %d\n", curr_block->magic );
		return NULL;
	}
	ft_putstr("realloc_in_0\n");
	if (curr_block->size < alligned_size)
	{
		ft_putstr("realloc_in\n");
		if (curr_block->next && curr_block->next->is_free
			&& curr_block->next->size + curr_block->size + BLOCK_SIZE >= alligned_size)
			{
				//printf("curr_block->next && curr_block->next->is_free\n\n");
				ft_putstr("curr_block->next && curr_block->next->is_free\n\n");
				memory_fusion(curr_block);
				if ((curr_block->size - alligned_size) >=  (BLOCK_SIZE + 8))
				{
					split_free_block(curr_block,alligned_size);
				}
			}
			else
			{
				//printf("!!!! No curr_block->next && curr_block->next->is_free\n\n");
				ft_putstr("!!!! No curr_block->next && curr_block->next->is_free\n\n");
				//if (!(new_ptr = malloc_1(alligned_size)))
				if (!(new_ptr = malloc(alligned_size)))
					return NULL;
				//new_block = get_block(new_ptr);
				ft_putstr("memcpy\n");
				ft_memcpy(new_ptr, ptr, curr_block->size < alligned_size ? curr_block->size :  alligned_size);
				//free_1(ptr);
				ft_putstr("free ptr\n");
				free(ptr);
				return new_ptr;

			}
		}
		else
		{
			//printf("curr_block->size >= alligned_size\n\n ");
			if ((curr_block->size - alligned_size) >=  (BLOCK_SIZE + 8))
			{
				ft_putstr("split current block for realloc\n");
				split_free_block(curr_block, alligned_size);
				curr_block->is_free = 0;
			} else
			{
				ft_putstr("split current block for realloc\n");
				return NULL;
			}
		}
		return ptr;
}

void		split_free_page(t_block *memory, size_t size)
{
	t_block *new_memory_block;


	if (size > getpagesize() - BLOCK_SIZE)
		return;
	//	ft_putstr("split_free_page_0\n");
	new_memory_block = MEMORY_DATA(memory) + size;
	//ft_putstr("split_free_page_0_1\n");
	new_memory_block->size = getpagesize() - BLOCK_SIZE - size;
	//ft_putstr("split_free_page_1\n");
	new_memory_block->next = memory->next;
	new_memory_block->prev = memory;
	new_memory_block->is_free = 1;
	new_memory_block->magic = memory->magic;
	memory->size = size;
	memory->next = new_memory_block;
	//ft_putstr("split_free_page_2\n");
	if (new_memory_block->next)
		new_memory_block->next->prev = new_memory_block;
}

void		split_free_block(t_block *memory, size_t size)
{
	t_block *new_memory_block;


	new_memory_block = MEMORY_DATA(memory) + size;
	new_memory_block->size = memory->size - BLOCK_SIZE - size;
	new_memory_block->next = memory->next;
	new_memory_block->prev = memory;
	new_memory_block->is_free = 1;
	new_memory_block->magic = memory->magic;
	memory->size = size;
	memory->next = new_memory_block;
	if (new_memory_block->next)
		new_memory_block->next->prev = new_memory_block;
}

t_block 	*find_free_block(size_t size, t_block ** last_block)//, int preallocate)
{
	t_block *cursor;

	cursor = *memory_begin();
	while (cursor && !(cursor->size >= size && cursor->is_free))
	{
		//if (preallocate)
		*last_block = cursor;
		cursor = cursor->next;
	}
	//preallocate = 1;
	return cursor;
}

t_block 	*add_new_memory_block(size_t size, t_block *last_block)
{
	t_block *begin;
	t_block *new_block;

	new_block = (t_block*)mmap(NULL, align8(size + BLOCK_SIZE),
					PROT_READ | PROT_WRITE,	MAP_PRIVATE | MAP_ANON, -1, 0);
	initiate_new_block(new_block, size);
	begin = *memory_begin();
	if (*memory_begin() == NULL)
	{
		*memory_begin() = new_block;
	}
	else
	{
		if (last_block)
			last_block->next = new_block;
		new_block->prev = last_block;
		(*memory_end()) = new_block;
	}
	return new_block;
}

void 		initiate_new_block(t_block *new_block, size_t size)
{
	new_block->size = size;
	new_block->is_free = 0;
	new_block->prev = NULL;
	new_block->next = NULL;
	new_block->magic = 123;
}

t_block 	*memory_fusion(t_block *memory)
{
	if (memory->next && memory->next->is_free)
	{
		memory->size += BLOCK_SIZE + memory->next->size;
		memory->next = memory->next->next;
		if (memory->next)
		{
			memory->next->prev = memory;
		}
	}
	return memory;
}
