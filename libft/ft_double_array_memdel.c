/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_memdel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:16:17 by mrassokh          #+#    #+#             */
/*   Updated: 2018/04/08 13:16:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_array_memdel(void ***pointer)
{
	int		i;

	if (!pointer)
		return ;
	i = 0;
	while ((*pointer)[i++])
	{
		free((*pointer)[i - 1]);
		(*pointer)[i - 1] = NULL;
	}
	free(*pointer);
	*pointer = NULL;
}
