/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:02:24 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/30 23:34:46 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_type(va_list args, const char type)
{
	int	type_len;

	type_len = 0;
	if (type == 'c')
		type_len += process_c(va_arg(args, int));
	else if (type == 's')
		type_len += process_s(va_arg(args, char *));
	else if (type == 'p')
	{
		type_len += write(1, "0x", 2);
		type_len += process_p(va_arg(args, unsigned long int));
	}
	else if (type == 'd' || type == 'i')
		type_len += process_di(va_arg(args, int));
	else if (type == 'u')
		type_len += process_u(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		type_len += process_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		type_len += process_percent();
	return (type_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += process_type(args, format[i + 1]);
			i++;
		}
		else
			length += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}
