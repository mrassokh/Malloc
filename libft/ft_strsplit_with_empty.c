/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_with_empty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:12:55 by mrassokh          #+#    #+#             */
/*   Updated: 2018/04/19 08:12:58 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		counter++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (counter);
}

static void		write_words(char const *s, char c, char **ret)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	word_num;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		ret[word_num++] = ft_strsub(s, start, end - start);
		if (s[i] == '\0')
			break ;
		i++;
	}
}

char			**ft_strsplit_with_empty(char const *s, char c)
{
	char	**ret;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!ret)
		return (NULL);
	write_words(s, c, ret);
	ret[words_count] = NULL;
	return (ret);
}
