/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:22:50 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 11:22:58 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		vectors_minus(t_vector *res, t_vector *a, t_vector *b)
{
	if (!res || !a || !b)
		return ;
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
}
