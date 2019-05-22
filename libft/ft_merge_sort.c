/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:46:29 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 16:13:53 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_intarray(int *dst, int *src, size_t start, size_t len)
{
	size_t	i;

	if (!dst || !src)
		return ;
	i = 0;
	while (i++ < len)
		dst[i - 1] = src[start + i - 1];
}

static void		merge(int *first, int *second, int *array, size_t len)
{
	size_t	med;
	size_t	i;
	size_t	j;
	size_t	k;

	med = len / 2;
	i = 0;
	j = 0;
	k = 0;
	while (i < med && j < len - med)
	{
		if (first[i] <= second[j])
			array[k++] = first[i++];
		else
			array[k++] = second[j++];
	}
	if (i == med)
		while (k < len)
			array[k++] = second[j++];
	else
		while (k < len)
			array[k++] = first[i++];
}

int				*ft_merge_sort(int *array, int len)
{
	int		mediana;
	int		*first;
	int		*second;

	if (len > 1)
	{
		mediana = len / 2;
		first = (int *)malloc(sizeof(int) * mediana);
		second = (int *)malloc(sizeof(int) * (len - mediana));
		write_intarray(first, array, 0, mediana);
		write_intarray(second, array, mediana, len - mediana);
		ft_merge_sort(first, mediana);
		ft_merge_sort(second, len - mediana);
		merge(first, second, array, len);
	}
	return (array);
}
