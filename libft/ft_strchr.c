/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:54:08 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:03:09 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ps;

	ps = s;
	while (*ps++)
		if (*(ps - 1) == (unsigned char)c)
			return ((char *)(ps - 1));
	if ((unsigned char)c == '\0')
		return ((char *)(ps - 1));
	return (NULL);
}
