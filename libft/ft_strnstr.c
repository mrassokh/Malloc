/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:52:42 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 14:21:28 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p1;
	const char	*p2;
	size_t		i;
	int			diff;

	if (*little == '\0')
		return ((char *)big);
	p1 = big;
	diff = len - ft_strlen(little);
	while (*p1)
	{
		p2 = little;
		i = 0;
		while (p2[i++] && p1[i - 1])
			if (p2[i - 1] != p1[i - 1])
				break ;
		if (diff-- < 0)
			break ;
		if (!p2[i - 1])
			return ((char *)big);
		p1 = ++big;
	}
	return (NULL);
}
