/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_masht_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:13:48 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/04 11:10:50 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*create_masht_m(float x, float y, float z, float s)
{
	t_matr	*ret;

	if (!(ret = create_single_m(4)))
		return (NULL);
	ret->mt[0][0] = x;
	ret->mt[1][1] = y;
	ret->mt[2][2] = z;
	ret->mt[3][3] = s;
	return (ret);
}
