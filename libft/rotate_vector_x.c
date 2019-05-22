/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:00:56 by mrassokh          #+#    #+#             */
/*   Updated: 2017/03/16 15:00:57 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void		rotate_vector_x(t_vector *res, t_vector *orig, float fi)
{
	fi = M_PI * fi / 180;
	res->y = orig->y * cos(fi) - orig->z * sin(fi);
	res->z = orig->y * sin(fi) + orig->z * cos(fi);
}

static void		rotate_vector_y(t_vector *res, t_vector *orig, float fi)
{
	fi = M_PI * fi / 180;
	res->x = orig->x * cos(fi) + orig->z * sin(fi);
	res->z = -orig->x * sin(fi) + orig->z * cos(fi);
}

static void		rotate_vector_z(t_vector *res, t_vector *orig, float fi)
{
	fi = M_PI * fi / 180;
	res->x = orig->x * cos(fi) - orig->y * sin(fi);
	res->y = orig->x * sin(fi) + orig->y * cos(fi);
}

void			rotate_vector(t_vector *res, t_vector *orig, t_vector *r)
{
	t_vector	t_swap;
	t_vector	t_swap_1;
	t_vector	t_swap_2;

	t_swap.x = 0;
	t_swap.y = 0;
	t_swap.z = 0;
	vector_is(&t_swap_1, t_swap);
	vector_is(&t_swap_2, t_swap);
	rotate_vector_x(&t_swap, orig, r->x);
	rotate_vector_y(&t_swap_1, &t_swap, r->y);
	rotate_vector_z(&t_swap_2, &t_swap_1, r->z);
	vector_is(res, t_swap_2);
}
