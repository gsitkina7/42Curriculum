/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:23:20 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 15:25:37 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*res;
	char	res_c;
	size_t	i;

	i = 0;
	res = (char *)s;
	res_c = (char)c;
	while (n--)
	{
		if (*res == res_c)
			return (res);
		res++;
	}
	return (NULL);
}
