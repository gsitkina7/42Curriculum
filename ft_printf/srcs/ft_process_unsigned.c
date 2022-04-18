/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:56:56 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/31 00:53:59 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_u(unsigned int nbr)
{
	int	u_len;

	u_len = 0;
	if (nbr >= 10)
	{
		u_len += process_u(nbr / 10);
		u_len += process_u(nbr % 10);
	}
	else
		u_len += process_c(nbr + 48);
	return (u_len);
}
