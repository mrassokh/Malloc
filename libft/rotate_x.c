/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:04:54 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/11 19:17:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*rotate_x(float fi)
{
	t_matr	*ret;

	if (!(ret = create_single_m(4)))
		return (NULL);
	ret->mt[1][1] = cos(fi);
	ret->mt[1][2] = -sin(fi);
	ret->mt[2][1] = sin(fi);
	ret->mt[2][2] = cos(fi);
	return (ret);
}
