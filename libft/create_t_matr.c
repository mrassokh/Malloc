/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_matr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 09:57:03 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/11 09:37:13 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*create_t_matr(float fi_x, float fi_y, float fi_z)
{
	t_matr	*rot_x;
	t_matr	*rot_y;
	t_matr	*rot_z;
	t_matr	*rot_xy;
	t_matr	*ret;

	if (fi_x)
		rot_x = rotate_x(M_PI * fi_x / 180);
	else
		rot_x = create_single_m(4);
	if (fi_y)
		rot_y = rotate_y(M_PI * fi_y / 180);
	else
		rot_y = create_single_m(4);
	if (fi_z)
		rot_z = rotate_z(M_PI * fi_z / 180);
	else
		rot_z = create_single_m(4);
	rot_xy = matrix_mult(rot_x, rot_y);
	ret = matrix_mult(rot_xy, rot_z);
	return (ret);
}

t_matr		*create_par_matrix(float par_alpha, float par_k)
{
	t_matr	*ret;

	ret = create_single_m(4);
	(ret->mt)[2][1] = par_k * cos(M_PI * par_alpha / 180);
	(ret->mt)[2][0] = par_k * sin(M_PI * par_alpha / 180);
	return (ret);
}

t_matr		*create_central_matrix(float zet)
{
	t_matr	*ret;

	ret = create_single_m(4);
	(ret->mt)[2][3] = 1 / zet;
	return (ret);
}
