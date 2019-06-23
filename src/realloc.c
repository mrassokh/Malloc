/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:32:40 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 11:32:42 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*expand_to_next_block(void *ptr, t_block *it, size_t size)
{
	memory_fusion(it);
	if ((it->size - size) >= (BLOCK_SIZE + 8))
		split_free_block(it, size);
	return (ptr);
}

void			*copy_to_new_block(void *ptr, t_block *it, size_t size)
{
	void		*new_ptr;

	if (!(new_ptr = malloc(size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, it->size < size ? it->size : size);
	free(ptr);
	return (new_ptr);
}

void			*expand_or_realloc(void *ptr, t_block *it, size_t size)
{
	if (it->next && it->next->is_free
		&& it->next->size + it->size + BLOCK_SIZE >= size)
		return (expand_to_next_block(ptr, it, size));
	else
		return (copy_to_new_block(ptr, it, size));
}

void			*realloc(void *ptr, size_t size)
{
	t_block		*it;
	size_t		a_size;

	if (!ptr)
		return (malloc(size));
	if (!valid_addr(ptr))
		return (NULL);
	a_size = ALLIGN8(size);
	it = GET_BLOCK_POINTER(ptr);
	if (it->magic != 123 && it->magic != 456)
		return (NULL);
	if (it->size < a_size)
		return (expand_or_realloc(ptr, it, a_size));
	else
	{
		if ((it->size - a_size) >= (BLOCK_SIZE + 8))
		{
			split_free_block(it, a_size);
			it->is_free = 0;
		}
		else
			return (NULL);
	}
	return (ptr);
}
