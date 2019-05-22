/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 10:46:42 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/25 10:46:44 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

int			rotate_z_a(t_matr *res, float fi)
{
	if (!res)
		return (0);
	res->mt[0][0] = cos(fi);
	res->mt[0][1] = -sin(fi);
	res->mt[1][0] = sin(fi);
	res->mt[1][1] = cos(fi);
	return (1);
}