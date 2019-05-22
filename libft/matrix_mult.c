/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:55:08 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/04 11:10:12 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr				*allocate_matrix(size_t h, size_t w)
{
	size_t	i;
	t_matr	*ret;

	if (!(ret = (t_matr *)malloc(sizeof(t_matr))))
		return (NULL);
	ret->h = h;
	ret->w = w;
	if (!(ret->mt = (float **)malloc(sizeof(float *) * h)))
		return (NULL);
	i = 0;
	while (i++ < h)
		if (!((ret->mt)[i - 1] = (float *)malloc(sizeof(float) * w)))
			return (NULL);
	return (ret);
}

float				new_chamber(int i, int j, t_matr *m1, t_matr *m2)
{
	float	ret;
	size_t	n;

	n = 0;
	ret = 0;
	while (n < m2->h)
	{
		ret += (m1->mt)[i][n] * (m2->mt)[n][j];
		n++;
	}
	return (ret);
}

t_matr				*matrix_mult(t_matr *m1, t_matr *m2)
{
	size_t	i;
	size_t	j;
	t_matr	*ret;

	if (m1->w != m2->h || !(ret = allocate_matrix(m1->h, m2->w)))
		return (NULL);
	i = 0;
	while (i < m1->h)
	{
		j = 0;
		while (j < m2->w)
		{
			ret->mt[i][j] = new_chamber(i, j, m1, m2);
			j++;
		}
		i++;
	}
	return (ret);
}
