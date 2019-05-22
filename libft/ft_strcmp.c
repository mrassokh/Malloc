/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:59:07 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:08:32 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		ret;
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		ret = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (ret != 0)
			return (ret);
		i++;
	}
	if (!s2[i] && s1[i])
		return ((int)((unsigned char)s1[i]));
	if (!s1[i] && s2[i])
		return (-(int)((unsigned char)s2[i]));
	return (0);
}
