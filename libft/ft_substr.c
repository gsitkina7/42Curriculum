/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:29:02 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 14:03:40 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
	{
		sub_s = malloc(sizeof(char));
		sub_s[0] = '\0';
		return (sub_s);
	}
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	sub_s = malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
