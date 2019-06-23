/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:01:00 by mrassokh          #+#    #+#             */
/*   Updated: 2019/06/23 11:01:04 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		**memory_begin(void)
{
	return (&memory_list()->memory_begin);
}

t_block		**tiny_segment(void)
{
	return (&memory_list()->tiny_segment);
}

t_block		**small_segment(void)
{
	return (&memory_list()->small_segment);
}

t_block		**memory_end(void)
{
	return (&memory_list()->memory_list_end);
}

t_block		**large_segment(void)
{
	return (&memory_list()->large_segment);
}
