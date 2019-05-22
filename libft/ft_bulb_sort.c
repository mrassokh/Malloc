/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bulb_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:30:00 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 11:49:37 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_bulb_sort(int *array, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (array[j + 1] < array[j])
				ft_swap(&(array[j]), &(array[j + 1]));
			j++;
		}
		i++;
	}
	return (array);
}
