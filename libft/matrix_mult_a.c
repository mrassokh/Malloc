/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 10:59:19 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/25 10:59:21 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

int				matrix_mult_a(t_matr *res, t_matr *m1, t_matr *m2)
{
	size_t	i;
	size_t	j;

	if (!res || !m1 || !m2 || m1->w != m2->h)
		return (0);
	i = 0;
	while (i < m1->h)
	{
		j = 0;
		while (j < m2->w)
		{
			res->mt[i][j] = new_chamber(i, j, m1, m2);
			j++;
		}
		i++;
	}
	return (1);
}
