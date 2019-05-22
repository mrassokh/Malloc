/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:46:07 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/27 13:04:20 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	i = 0;
	if (!s || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	if (ret)
		while (s[i++])
			ret[i - 1] = (*f)(i - 1, s[i - 1]);
	return (ret);
}
