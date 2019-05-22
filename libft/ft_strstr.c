/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:14:12 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:06:48 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*p1;
	const char	*p2;
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	p1 = big;
	while (*p1)
	{
		p2 = little;
		i = 0;
		while (p2[i++] && p1[i - 1])
			if (p2[i - 1] != p1[i - 1])
				break ;
		if (!p2[i - 1])
			return ((char *)big);
		big++;
		p1 = big;
	}
	return (NULL);
}
