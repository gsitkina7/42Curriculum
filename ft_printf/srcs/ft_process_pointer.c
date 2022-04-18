/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:16:56 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/31 00:59:50 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_p(unsigned long int ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr >= 16)
	{
		ptr_len += process_p(ptr / 16);
		ptr_len += process_p(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ptr_len += process_c(ptr + 48);
		else
			ptr_len += process_c(ptr + 87);
	}
	return (ptr_len);
}
