/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:15:53 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/09 23:40:08 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	finish;

	start = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	finish = ft_strlen(s1);
	while (finish && ft_strchr(set, s1[finish]))
		finish--;
	res = ft_substr(s1, 0, finish + 1);
	return (res);
}
