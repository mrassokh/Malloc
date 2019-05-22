/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:45:37 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 13:46:57 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_choose_sort(int *array, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = ++i;
		while (j++ < len)
			if (array[j - 1] < array[i - 1])
				ft_swap(array + j - 1, array + i - 1);
	}
	return (array);
}
