/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:10:28 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/12 01:36:23 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_int_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		n_len;

	n_len = find_int_len(n);
	res = malloc(sizeof(char) * n_len + 1);
	if (res == NULL)
		return (NULL);
	res[n_len] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--n_len;
		res[n_len] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
