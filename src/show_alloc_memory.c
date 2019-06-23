/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:06:44 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 11:06:46 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		print_segment_header(t_block *cursor)
{
	char		*address_str;

	if (cursor == *tiny_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("TINY : 0x");
		ft_putendl(address_str);
		free(address_str);
	}
	if (cursor == *small_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("SMALL : 0x");
		ft_putendl(address_str);
		free(address_str);
	}
	if (cursor == *large_segment())
	{
		address_str = ft_itoa_base((uint64_t)cursor, 16, 1);
		ft_putstr("LARGE : 0x");
		ft_putendl(address_str);
		free(address_str);
	}
}

void		print_block_info(t_block *cursor)
{
	char		*address_str;
	char		*size;
	uint64_t	address;

	address = (uint64_t)cursor + BLOCK_SIZE;
	size = ft_itoa_base((uint64_t)(cursor->size), 10, 1);
	address_str = ft_itoa_base(address, 16, 1);
	ft_putstr("0x");
	ft_putstr(address_str);
	ft_putstr(" - ");
	free(address_str);
	address += (uint64_t)(cursor->size);
	address_str = ft_itoa_base(address, 16, 1);
	ft_putstr("0x");
	ft_putstr(address_str);
	free(address_str);
	ft_putstr(" : ");
	ft_putstr(size);
	free(size);
	ft_putendl(" bytes");
}

void		show_alloc_mem(void)
{
	t_block *cursor;
	size_t	total;
	char	*total_size;

	total = 0;
	cursor = *memory_begin();
	if (!cursor)
		ft_putendl("empty memory list!!!");
	while (cursor)
	{
		print_segment_header(cursor);
		if (!cursor->is_free && cursor->size)
		{
			total += cursor->size;
			print_block_info(cursor);
		}
		cursor = cursor->next;
	}
	total_size = ft_itoa_base(total, 10, 1);
	ft_putstr("Total : ");
	ft_putstr(total_size);
	ft_putendl(" bytes");
	free(total_size);
}
