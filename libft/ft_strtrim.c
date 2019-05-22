/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 07:27:57 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 09:50:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char		*ret;
	size_t		start;
	size_t		end;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_iswspace(s[i]))
		i++;
	start = i;
	end = i;
	while (s[i])
	{
		while (s[i] && !ft_iswspace(s[i]))
			i++;
		end = i;
		while (s[i] && ft_iswspace(s[i]))
			i++;
	}
	ret = ft_strsub(s, start, end - start);
	return (ret);
}
