/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shift_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:59:15 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/11 07:52:50 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

t_matr		*create_shift_m(float x_shift, float y_shift, float z_shift)
{
	t_matr	*ret;

	if (!(ret = create_single_m(4)))
		return (NULL);
	ret->mt[3][0] = x_shift;
	ret->mt[3][1] = y_shift;
	ret->mt[3][2] = z_shift;
	return (ret);
}
