/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:36:52 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 12:56:23 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			ret;
	const char	*str1;
	const char	*str2;

	ret = 0;
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	while (n--)
	{
		ret = (unsigned char)(*str1++) - (unsigned char)(*str2++);
		if (ret != 0)
			return (ret);
	}
	return (ret);
}
