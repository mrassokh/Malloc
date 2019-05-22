/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shift_m_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 10:35:57 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/25 10:36:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

int		create_shift_m_a(t_matr *res, float x_sh, float y_sh, float z_sh)
{
	if (!res)
		return (0);
	res->mt[3][0] = x_sh;
	res->mt[3][1] = y_sh;
	res->mt[3][2] = z_sh;
	return (1);
}
