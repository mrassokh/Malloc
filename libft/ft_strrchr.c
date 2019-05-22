/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:45:36 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:06:14 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ps;
	char		*ret;

	ps = s;
	ret = NULL;
	while (*ps++)
		if (*(ps - 1) == (unsigned char)c)
			ret = (char *)(ps - 1);
	if ((unsigned char)c == '\0')
		ret = (char *)(ps - 1);
	return (ret);
}
