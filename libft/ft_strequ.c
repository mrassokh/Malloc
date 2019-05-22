/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:10:25 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/27 14:39:06 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		ret = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (ret != 0)
			return (0);
		i++;
	}
	if (!s1[i] && !s2[i])
		return (1);
	else
		return (0);
}
