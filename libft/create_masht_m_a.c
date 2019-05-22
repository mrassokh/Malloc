/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_masht_m_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:35:51 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 17:36:21 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

int		create_masht_m_a(t_matr *res, float x, float y, float z)
{
	if (!res)
		return (0);
	res->mt[0][0] = x;
	res->mt[1][1] = y;
	res->mt[2][2] = z;
	res->mt[3][3] = 1;
	return (1);
}
