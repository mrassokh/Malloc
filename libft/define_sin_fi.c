/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_sin_fi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:32:48 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 16:32:49 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		define_sin_fi(t_vector *a, t_vector *b)
{
	double		sin_fi;
	double		abs_a;
	double		abs_b;
	t_vector	cross;

	abs_a = vector_abs(a);
	abs_b = vector_abs(b);
	vector_product(&cross, a, b);
	sin_fi = vector_abs(&cross) / (abs_a * abs_b);
	return (sin_fi);
}
