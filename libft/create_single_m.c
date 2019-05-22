/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_single_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:50:47 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/04 11:14:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*create_single_m(size_t size)
{
	t_matr	*single_m;
	size_t	i;
	size_t	j;

	if (!(single_m = allocate_matrix(size, size)))
		return (NULL);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j++ < size)
			if (j - 1 == i - 1)
				(single_m->mt)[i - 1][j - 1] = 1;
			else
				(single_m->mt)[i - 1][j - 1] = 0;
	}
	return (single_m);
}
