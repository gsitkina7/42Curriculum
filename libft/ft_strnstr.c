/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:46:02 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 15:39:00 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*from;
	char	*to_find;
	size_t	i;
	size_t	j;

	from = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	if (!*to_find)
		return (from);
	while (i < len && from[i])
	{
		if (from[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && to_find[j] == from[i + j] && i + j < len)
				j++;
			if (to_find[j] == '\0')
				return (&from[i]);
		}
		i++;
	}
	return (NULL);
}
