/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:21:55 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/11 19:23:15 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*rotate_y(float fi)
{
	t_matr	*ret;

	if (!(ret = create_single_m(4)))
		return (NULL);
	ret->mt[0][0] = cos(fi);
	ret->mt[0][2] = sin(fi);
	ret->mt[2][0] = -sin(fi);
	ret->mt[2][2] = cos(fi);
	return (ret);
}
