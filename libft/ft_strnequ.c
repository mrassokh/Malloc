/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:38:24 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/27 15:06:35 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int			ret;
	size_t		i;

	ret = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		ret = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (ret != 0)
			return (0);
		i++;
	}
	if (i >= n)
		return (1);
	else if (!s1[i] && !s2[i])
		return (1);
	else
		return (0);
}
