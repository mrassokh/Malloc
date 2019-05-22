/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:31:33 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 11:31:38 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*create_vector(double x, double y, double z)
{
	t_vector *ret;

	if (!(ret = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
