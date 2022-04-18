/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:42:43 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/09 11:29:30 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		res++;
	}
	return (res);
}

static char	*next_word(char const *s, int *start, char c)
{
	char	*word;
	int		i;

	while (s[*start] == c)
		if (s[(*start)++] == '\0')
			return (NULL);
	i = 0;
	while (s[*start + i] != c && s[*start + i])
		i++;
	if (i != 0)
	{
		word = malloc(sizeof(char) * (i + 1));
		if (!word)
			return (NULL);
		i = 0;
		while (s[*start] != c && s[*start])
			word[i++] = s[(*start)++];
		word[i] = '\0';
	}
	else
		return (NULL);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	char	*word;
	int		*i;
	int		j;
	int		k;

	list = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!list)
		return (NULL);
	j = 0;
	i = &j;
	k = 0;
	while (k < word_count(s, c))
	{
		word = next_word(s, i, c);
		if (!word)
			return (NULL);
		list[k++] = word;
	}
	list[k] = NULL;
	return (list);
}
