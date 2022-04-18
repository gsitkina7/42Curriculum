/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:19:00 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/31 00:47:01 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_hex(unsigned int nbr, const char type)
{
	int	hex_len;

	hex_len = 0;
	if (nbr >= 16)
	{
		hex_len += process_hex(nbr / 16, type);
		hex_len += process_hex(nbr % 16, type);
	}
	else
	{
		if (nbr <= 9)
			hex_len += process_c(nbr + 48);
		else
		{
			if (type == 'x')
				hex_len += process_c(nbr + 87);
			else
				hex_len += process_c(nbr + 55);
		}
	}
	return (hex_len);
}
