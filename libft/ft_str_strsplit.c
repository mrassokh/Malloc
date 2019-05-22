/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:12:21 by mrassokh          #+#    #+#             */
/*   Updated: 2018/04/19 08:12:31 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char const *incl)
{
	size_t	counter;
	char	*include_happen;

	include_happen = ft_strstr(s, incl);
	counter = 1;
	while (include_happen)
	{
		counter++;
		include_happen = ft_strstr(include_happen + ft_strlen(incl), incl);
	}
	return (counter);
}

static void		write_words(char const *s, char const *incl, char **ret, int w)
{
	int		word_num;
	char	*start;
	char	*end;

	start = (char *)s;
	word_num = 0;
	while (word_num++ < w)
	{
		if ((end = ft_strstr(start, incl)))
		{
			ret[word_num - 1] = ft_strsub(s, start - s, end - start);
			start = end + ft_strlen(incl);
		}
		else
		{
			ret[word_num - 1] = ft_strsub(s, start - s,
									ft_strlen(s) - (start - s));
		}
	}
}

char			**ft_str_strsplit(char const *s, char const *incl)
{
	char	**ret;
	size_t	words_count;

	if (!s || !incl)
		return (NULL);
	words_count = count_words(s, incl);
	ret = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!ret)
		return (NULL);
	write_words(s, incl, ret, words_count);
	ret[words_count] = NULL;
	return (ret);
}
