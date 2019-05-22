/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:55:03 by mrassokh          #+#    #+#             */
/*   Updated: 2017/03/16 16:55:05 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		vector_is(t_vector *res, t_vector origin)
{
	res->x = origin.x;
	res->y = origin.y;
	res->z = origin.z;
}
