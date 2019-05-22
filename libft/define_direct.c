/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_direct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:27:36 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/25 15:27:44 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		define_direct(t_vector *dir, t_vector *a)
{
	double		abs;

	abs = vector_abs(a);
	dir->x = a->x / abs;
	dir->y = a->y / abs;
	dir->z = a->z / abs;
}
