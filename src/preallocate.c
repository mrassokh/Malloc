/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preallocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:40:31 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 12:40:33 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		preallocate_free_check(void)
{
	t_block *cursor;

	if (memory_list()->count != -1)
		(memory_list()->count)++;
	if (memory_list()->count > 200)
	{
		cursor = *tiny_segment();
		while (cursor && cursor->magic == 456)
		{
			cursor->is_free = 1;
			cursor = cursor->next;
		}
		memory_list()->count = -1;
	}
}

void		fill_small_zone(t_block **last_block)
{
	int			i;
	t_block		*alloc_memory;

	i = 0;
	alloc_memory = add_new_memory_block(ALLIGN8(MAX_SMALL_BLOCK_SIZE),
														*last_block);
	*last_block = alloc_memory;
	*small_segment() = *last_block;
	alloc_memory->magic = 456;
	while (i++ < SMALL_N - 1)
	{
		alloc_memory = memory_allocate(ALLIGN8(MAX_SMALL_BLOCK_SIZE),
														*last_block);
		*last_block = alloc_memory;
		alloc_memory->magic = 456;
	}
}

void		fill_tiny_zone(t_block **last_block)
{
	int			i;
	t_block		*alloc_memory;

	i = 0;
	while (i++ < TINY_N)
	{
		alloc_memory = memory_allocate(ALLIGN8(MAX_TINY_BLOCK_SIZE),
														*last_block);
		*last_block = alloc_memory;
		alloc_memory->magic = 456;
	}
	*tiny_segment() = *memory_begin();
}

void		first_call_processing(void)
{
	fill_tiny_zone(memory_end());
	fill_small_zone(memory_end());
}
