/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:45:00 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/14 14:57:55 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = dst;
	s = (char *)src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (s < d)
	{
		while ((int)--len >= 0)
			*(d + len) = *(s + len);
	}
	else
	{
		while (++i < (int)len)
			*(d + i) = *(s + i);
	}
	return (d);
}
