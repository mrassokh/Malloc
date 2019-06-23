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

t_block		*add_new_memory_block(size_t size, t_block *last_block)
{
	t_block *begin;
	t_block *new_block;

	new_block = (t_block*)mmap(NULL, ALLIGN8(size + BLOCK_SIZE),
					PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
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
	return (new_block);
}

void		split_free_page(t_block *memory, size_t size)
{
	t_block *new_memory_block;

	if (size > getpagesize() - BLOCK_SIZE)
		return ;
	new_memory_block = MEMORY_DATA(memory) + size;
	new_memory_block->size = getpagesize() - BLOCK_SIZE - size;
	initiate_split_block(memory, new_memory_block, size);
}

void		split_free_block(t_block *memory, size_t size)
{
	t_block *new_memory_block;

	new_memory_block = MEMORY_DATA(memory) + size;
	new_memory_block->size = memory->size - BLOCK_SIZE - size;
	initiate_split_block(memory, new_memory_block, size);
}

t_block		*find_free_block(size_t size, t_block **last_block)
{
	t_block *cursor;

	cursor = *memory_begin();
	while (cursor && !(cursor->size >= size && cursor->is_free))
	{
		*last_block = cursor;
		cursor = cursor->next;
	}
	return (cursor);
}
