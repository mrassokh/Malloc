/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:06:56 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/28 09:18:29 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		counter++;
		while (s[i] && s[i] == c)
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
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		ret[word_num++] = ft_strsub(s, start, end - start);
		while (s[i] && s[i] == c)
			i++;
	}
}

char			**ft_strsplit(char const *s, char c)
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
