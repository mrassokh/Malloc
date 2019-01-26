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

void 	hello()
{
	char a = '\n';
	write(1, &a, 1);
	//printf("Hello world!!!\n");
}

void 	*malloc(size_t size)
{
	if (size == 0)
		return NULL;
	t_block *memory;
	t_block * last_block;

	last_block = NULL;
	memory = find_free_block(size, last_block);
	if (!memory)
		memory = add_new_memory_block(size, last_block);
	//split_free_block(memory, size);
	return MEMORY_DATA(memory);
}
