/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:24:27 by mrassokh          #+#    #+#             */
/*   Updated: 2018/04/17 19:24:31 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_quat			get_quaternion(t_vector *axe, const float w)
{
	float	angle;

	angle = sin(w * ANGLE / 2);
	return ((t_quat){axe->x * angle, axe->y * angle,
						axe->z * angle, cos(w * ANGLE / 2)});
}

t_quat			mul_quaternion(const t_quat a, const t_quat b)
{
	return ((t_quat){
		a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1],
		a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0],
		a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3],
		a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2]});
}

void			fill_rotate_matrix(t_quat *quaternion, float *matrix)
{
	float	tmp[9];

	ft_memset(matrix, 0, sizeof(float) * 16);
	tmp[0] = (*quaternion)[0] * (*quaternion)[0];
	tmp[1] = (*quaternion)[0] * (*quaternion)[1];
	tmp[2] = (*quaternion)[0] * (*quaternion)[2];
	tmp[3] = (*quaternion)[0] * (*quaternion)[3];
	tmp[4] = (*quaternion)[1] * (*quaternion)[1];
	tmp[5] = (*quaternion)[1] * (*quaternion)[2];
	tmp[6] = (*quaternion)[1] * (*quaternion)[3];
	tmp[7] = (*quaternion)[2] * (*quaternion)[2];
	tmp[8] = (*quaternion)[2] * (*quaternion)[3];
	matrix[0] = 1.0f - 2.0f * (tmp[4] + tmp[7]);
	matrix[1] = 2.0f * (tmp[1] - tmp[8]);
	matrix[2] = 2.0f * (tmp[2] + tmp[6]);
	matrix[4] = 2.0f * (tmp[1] + tmp[8]);
	matrix[5] = 1.0f - 2.0f * (tmp[0] + tmp[7]);
	matrix[6] = 2.0f * (tmp[5] - tmp[3]);
	matrix[8] = 2.0f * (tmp[2] - tmp[6]);
	matrix[9] = 2.0f * (tmp[5] + tmp[3]);
	matrix[10] = 1.0f - 2.0f * (tmp[0] + tmp[4]);
	matrix[15] = 1.0f;
}
