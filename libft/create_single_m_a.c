/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_single_m_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:27:40 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 17:27:41 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

int		create_single_m_a(t_matr *res, size_t size)
{
	size_t	i;
	size_t	j;

	if (!res)
		return (0);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j++ < size)
			if (j - 1 == i - 1)
				(res->mt)[i - 1][j - 1] = 1;
			else
				(res->mt)[i - 1][j - 1] = 0;
	}
	return (1);
}
