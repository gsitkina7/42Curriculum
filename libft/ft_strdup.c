/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:59:57 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 15:42:01 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s1);
	res = malloc(sizeof(char) * s_len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < s_len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
