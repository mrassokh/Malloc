/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:59:56 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:59 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int					valid_addr(void *ptr)
{
	t_block *begin;

	begin = *memory_begin();
	if (begin)
	{
		if (ptr > (void *)(begin + 1) && ptr <= (void *)(*memory_end() + 1))
		{
			return (ptr == GET_BLOCK_POINTER(ptr) + BLOCK_SIZE);
		}
	}
	return (0);
}

t_block				*memory_fusion(t_block *memory)
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
	return (memory);
}

void				free(void *ptr)
{
	t_block *memory;

	memory = GET_BLOCK_POINTER(ptr);
	if (!valid_addr(ptr) || memory->is_free)
		return ;
	if (memory->magic != 123 && memory->magic != 456)
		return ;
	memory->is_free = 1;
	if (memory->prev && memory->prev->is_free && memory->magic != 456)
		memory = memory_fusion(memory->prev);
	if (memory->next)
	{
		memory_fusion(memory);
	}
	else if (!memory->prev)
	{
		(*memory_begin()) = NULL;
		(*memory_end()) = NULL;
		munmap(memory, memory->size);
	}
}
