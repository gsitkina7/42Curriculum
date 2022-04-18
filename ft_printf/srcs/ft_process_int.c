/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:33:03 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/30 23:13:32 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_int_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	int		nbr_len;
	char	*res;

	nbr_len = find_int_len(nbr);
	res = malloc(sizeof(char) * (nbr_len + 1));
	if (!res)
		return (NULL);
	res[nbr_len] = '\0';
	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
	while (nbr != 0)
	{
		res[nbr_len - 1] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
		nbr_len--;
	}
	return (res);
}

int	process_di(int nbr)
{
	int		di_len;
	char	*num_res;

	num_res = ft_itoa(nbr);
	di_len = process_s(num_res);
	free(num_res);
	return (di_len);
}
