/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:23:18 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 15:18:57 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = (char *)s;
	i = ft_strlen(res) + 1;
	while (i--)
	{
		if (*(res + i) == (char)c)
			return ((char *)res + i);
	}
	return (NULL);
}
