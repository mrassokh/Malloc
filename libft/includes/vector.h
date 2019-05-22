/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:21:41 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 11:21:48 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <math.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_roots
{
	double		t1;
	double		t2;
}				t_roots;

t_vector		*create_vector(double x, double y, double z);
void			vectors_add(t_vector *res, t_vector *a, t_vector *b);
void			vectors_minus(t_vector *res, t_vector *a, t_vector *b);
double			dot_product(t_vector *a, t_vector *b);
double			vector_abs(t_vector *a);
double			define_cos_fi(t_vector *a, t_vector *b);
void			vector_product(t_vector *res, t_vector *a, t_vector *b);
int				square_eq(t_roots *root, double a, double b, double c);
double			define_sin_fi(t_vector *a, t_vector *b);
void			define_direct(t_vector *dir, t_vector *a);
void			vector_product_float(t_vector *a, double k);
void			rotate_vector(t_vector *res, t_vector *orig, t_vector *r);
void			vector_is(t_vector *res, t_vector origin);
void			vector_set(t_vector *res, double x, double y, double z);
#endif
