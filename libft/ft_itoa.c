/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:57:00 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 11:19:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		check_input(int *n, size_t *len, int *min)
{
	if (*n < -2147483647)
	{
		(*len)++;
		*n = 2147483647;
		*min = 1;
	}
	if (*n < 0)
	{
		(*len)++;
		*n = -(*n);
	}
}

static	void	print_string(int n, char *ret, size_t len, int min)
{
	if (!n)
		ret[--len] = '0';
	while (n)
	{
		ret[--len] = '0' + n % 10;
		n = n / 10;
	}
	if (len)
		ret[--len] = '-';
	if (min)
		ret[10] = '8';
}

char			*ft_itoa(int n)
{
	size_t	len;
	int		nd;
	char	*ret;
	int		min;

	min = 0;
	len = 1;
	check_input(&n, &len, &min);
	nd = n;
	while (nd /= 10)
		len++;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	print_string(n, ret, len, min);
	return (ret);
}
