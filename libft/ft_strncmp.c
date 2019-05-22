/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:08:02 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 13:09:25 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	int		i;

	i = 0;
	while (s1[i] && s2[i] && n--)
	{
		ret = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (ret != 0)
			return (ret);
		i++;
	}
	if (!s2[i] && s1 && n)
		return ((int)((unsigned char)s1[i]));
	if (!s1[i] && s2 && n)
		return (-(int)((unsigned char)s2[i]));
	return (0);
}
