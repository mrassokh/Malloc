/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:57:40 by mrassokh          #+#    #+#             */
/*   Updated: 2018/04/13 10:57:42 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_identity_matrix(float *identity)
{
	ft_memset(identity, 0, sizeof(float) * 16);
	identity[0] = 1;
	identity[5] = 1;
	identity[10] = 1;
	identity[15] = 1;
}

void	fill_translate_matrix(float *translate, t_vector *v_translate)
{
	fill_identity_matrix(translate);
	translate[12] = v_translate->x;
	translate[13] = v_translate->y;
	translate[14] = v_translate->z;
}

void	fill_scale_matrix(float *scale, t_vector *v_scale)
{
	fill_identity_matrix(scale);
	scale[0] = v_scale->x;
	scale[5] = v_scale->y;
	scale[10] = v_scale->z;
}
