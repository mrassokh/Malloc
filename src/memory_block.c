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
	static t_block *memory_list = NULL;

	return (&memory_list);
}
//static t_block			**mem_list;

t_block 	*find_free_block(size_t size, t_block * last_block)
{
	t_block *cursor;

	last_block = NULL;
	cursor = *memory_list();
	while (cursor && cursor->size < size && !cursor->is_free)
	{
		last_block = cursor;
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
	if (!last_block)
	{
		begin = new_block;
	}
	else
	{
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

// void	split_free_block(t_block *memory, size_t size);
// {
//
// }
