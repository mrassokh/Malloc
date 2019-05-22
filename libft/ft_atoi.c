/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:10:19 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:59:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	converse(const char *str, int sign)
{
	long long int		num;

	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (int)(*str++) - (int)'0';
	}
	return ((int)(num * sign));
}

int			ft_atoi(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		return (converse(++str, 1));
	if (*str == '-')
		return (converse(++str, -1));
	return (converse(str, 1));
}
