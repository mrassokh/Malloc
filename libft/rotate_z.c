/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:21:55 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/11 19:25:24 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*rotate_z(float fi)
{
	t_matr	*ret;

	if (!(ret = create_single_m(4)))
		return (NULL);
	ret->mt[0][0] = cos(fi);
	ret->mt[0][1] = -sin(fi);
	ret->mt[1][0] = sin(fi);
	ret->mt[1][1] = cos(fi);
	return (ret);
}
