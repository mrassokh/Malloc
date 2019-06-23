/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:57:00 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 11:19:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

uint64_t	ft_power(uint64_t nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

int			ft_number_len(uint64_t nb, int base)
{
	int	length;

	length = 1;
	while (ft_power(base, length) <= nb)
		length++;
	return (length);
}

char		*ft_itoa_base(uint64_t n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	if (n > 1152921504606846976)
		length = 15;
	else
		length = ft_number_len(n, base);
	str = (char*)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
