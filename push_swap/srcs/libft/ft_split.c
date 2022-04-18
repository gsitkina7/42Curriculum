/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:42:43 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/08 11:19:24 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_word(char const *s, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (finish - start + 1));
	i = 0;
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			i++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	int		res_index;

	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (res == NULL || !s)
		return (NULL);
	i = 0;
	j = 0;
	res_index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && res_index < 0)
			res_index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && res_index >= 0)
		{
			res[j++] = make_word(s, res_index, i);
			res_index = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
