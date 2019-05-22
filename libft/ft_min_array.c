/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:32:39 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 12:11:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_array(int *array, int len)
{
	int		i;
	int		min;

	i = 0;
	min = array[i];
	while (i < len)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
