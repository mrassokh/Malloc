/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:06:44 by mrassokh          #+#    #+#             */
/*   Updated: 2017/03/02 14:06:45 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

float			define_decim(const char *str, int sign)
{
	int		n;
	float	d;
	float	decim;

	n = 0;
	d = 1.0;
	while (ft_isdigit(str[n]))
	{
		n++;
		d = d * 10;
	}
	decim = ((float)ft_atoi(str)) / d;
	return (sign * decim);
}

float			ft_atof(const char *str)
{
	float	ret;
	float	decim;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	decim = 0.0;
	while (ft_isspace(*str))
		str++;
	if (str[0] == '-')
	{
		i++;
		sign = -1;
	}
	while (ft_isdigit(str[i]))
		i++;
	ret = (float)ft_atoi(str);
	if (str[i] == '.')
		decim = define_decim(str + i + 1, sign);
	ret = ret + decim;
	return (ret);
}
