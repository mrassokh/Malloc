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

void		*calloc(size_t nitems, size_t size)
{
	size_t *ptr;
	size_t s8;

	ptr = malloc(nitems * size);
	if (ptr)
	{
		s8 = ALLIGN8(nitems * size);
		while (s8--)
		{
			ptr[s8] = 0;
		}
	}
	return (ptr);
}

t_block		*memory_allocate(size_t size, t_block *last_block)
{
	t_block *memory;

	memory = find_free_block(size, &last_block);
	if (!memory)
	{
		memory = add_new_memory_block(size, last_block);
		if (!memory)
			return (NULL);
		if ((getpagesize() - memory->size) > BLOCK_SIZE + 8)
		{
			split_free_page(memory, memory->size);
			memory->is_free = 0;
		}
	}
	else
	{
		if ((memory->size - size) > BLOCK_SIZE + 8 && memory->magic == 123)
			split_free_block(memory, size);
		memory->is_free = 0;
	}
	return (memory);
}

void		*malloc(size_t size)
{
	t_block		*memory;
	t_block		*last_block;
	t_block		*begin;
	size_t		size_allign;

	if (size == 0)
		return (NULL);
	size_allign = ALLIGN8(size);
	begin = *memory_begin();
	last_block = begin;
	if (!begin)
		first_call_processing();
	memory = memory_allocate(size_allign, last_block);
	if (!(*large_segment()) && memory->magic == 123)
		(*large_segment()) = memory;
	if (*large_segment())
		preallocate_free_check();
	return (MEMORY_DATA(memory));
}
