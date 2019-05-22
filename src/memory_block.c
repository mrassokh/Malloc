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

t_block 	**memory_list()
{
	static t_block *memory_list;

	return (&memory_list);
}
//static t_block			**mem_list;

void					*realloc_1(void *ptr, size_t size)
{
	void 		*new_ptr;
	t_block 	*curr_block;
	t_block 	*new_block;
	size_t		alligned_size;

	if (!ptr)
		return malloc_1(size);
	alligned_size = align4(size);
	curr_block = get_block(ptr);
	if (curr_block->size < alligned_size)
	{
		if (curr_block->next && curr_block->next->is_free
			&& curr_block->next->size + curr_block->size + BLOCK_SIZE >= alligned_size)
			{
				memory_fusion(curr_block);
				if ((curr_block->size - alligned_size) >=  (BLOCK_SIZE + 4))
				{
					split_free_block(curr_block,alligned_size);
				}
			}
			else
			{

				if (!(new_ptr = malloc_1(alligned_size)))
					return NULL;
				new_block = get_block(new_ptr);
				ft_memcpy(new_ptr, ptr, size);
				free_1(ptr);
				return new_ptr;

			}
		}
		else
		{
			if ((curr_block->size - alligned_size) >=  (BLOCK_SIZE + 4))
			{
				split_free_block(curr_block,alligned_size);
			}
		}
		return ptr;
}

void		split_free_block(t_block *memory, size_t size)
{
	t_block *new_memory_block;

	ft_putstr("find_free_block_start!\n");

	new_memory_block = MEMORY_DATA(memory) + size;
	new_memory_block->size = memory->size - BLOCK_SIZE - size;
	new_memory_block->next = memory->next;
	new_memory_block->prev = memory;
	new_memory_block->is_free = 1;
	memory->size = size;
	memory->next = new_memory_block;
	if (new_memory_block->next)
		new_memory_block->next->prev = new_memory_block;
}

t_block 	*find_free_block(size_t size, t_block ** last_block)
{
	t_block *cursor;

	//last_block = *memory_list();
	cursor = *memory_list();
	ft_putstr("find_free_block_start!\n");
	while (cursor && !(cursor->size >= size && cursor->is_free))
	{
		ft_putstr("find free in cycle!\n");
		*last_block = cursor;
		cursor = cursor->next;
	}

	// if (cursor) {
	// 	last_block = cursor->next;
	// }
	return cursor;
}

t_block 	*add_new_memory_block(size_t size, t_block *last_block)
{
	t_block *begin;
	t_block *new_block;

	new_block = (t_block*)mmap(NULL, align4(size + BLOCK_SIZE),
					PROT_READ | PROT_WRITE,	MAP_PRIVATE | MAP_ANON, -1, 0);
	initiate_new_block(new_block, size);
	begin = *memory_list();
	if (*memory_list() == NULL)
	{
		ft_putendl("aaaa!");
		*memory_list() = new_block;
	}
	else
	{
		ft_putendl("bbb!");
		if (last_block)
			last_block->next = new_block;
		new_block->prev = last_block;
	}
	return new_block;
	//if(*memory_list() == NULL;

}

void 		initiate_new_block(t_block *new_block, size_t size)
{
	new_block->size = size;
	new_block->is_free = 0;
	new_block->prev = NULL;
	new_block->next = NULL;
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
// void	split_free_block(t_block *memory, size_t size);
// {
//
// }
