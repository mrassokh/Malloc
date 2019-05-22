/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:33:04 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 12:59:49 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*pd;
	size_t	i;

	pd = dst;
	i = 0;
	while (src[i] && i < len)
	{
		pd[i] = src[i];
		i++;
	}
	while (i++ < len)
		pd[i - 1] = '\0';
	return (dst);
}
