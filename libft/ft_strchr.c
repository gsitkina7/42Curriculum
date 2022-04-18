/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:11:05 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 15:16:26 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (i < ft_strlen(res) + 1)
	{
		if (res[i] == (char)c)
			return ((char *)res + i);
		i++;
	}
	return (NULL);
}
