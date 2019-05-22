/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_cos_fi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:41:58 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 13:42:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		define_cos_fi(t_vector *a, t_vector *b)
{
	double		cos_fi;
	double		abs_a;
	double		abs_b;

	abs_a = vector_abs(a);
	abs_b = vector_abs(b);
	cos_fi = dot_product(a, b) / (abs_a * abs_b);
	return (cos_fi);
}
