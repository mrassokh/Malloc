/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:52:41 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 11:52:42 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_memory	*memory_list(void)
{
	static t_memory memory_list;

	return (&memory_list);
}

void		initiate_new_block(t_block *new_block, size_t size)
{
	new_block->size = size;
	new_block->is_free = 0;
	new_block->prev = NULL;
	new_block->next = NULL;
	new_block->magic = 123;
}

void		initiate_split_block(t_block *memory, t_block *new_memory_block,
													size_t size)
{
	new_memory_block->next = memory->next;
	new_memory_block->prev = memory;
	new_memory_block->is_free = 1;
	new_memory_block->magic = memory->magic;
	memory->size = size;
	memory->next = new_memory_block;
	if (new_memory_block->next)
		new_memory_block->next->prev = new_memory_block;
}
