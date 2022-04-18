/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:59:00 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/08 23:39:19 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		is_negative;
	size_t	i;

	num = 0;
	i = check_whitespace(str);
	is_negative = 1;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}
