/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_eq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:49:51 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 15:49:53 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		square_eq(t_roots *root, double a, double b, double c)
{
	double	d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	else
	{
		root->t1 = (-b + sqrt(d)) / (2 * a);
		root->t2 = (-b - sqrt(d)) / (2 * a);
	}
	return (1);
}
