/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:02:42 by ahertha           #+#    #+#             */
/*   Updated: 2021/12/31 00:54:09 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		process_type(va_list args, const char type);
int		process_c(int c);
int		process_s(char *s);
int		process_percent(void);
int		process_p(unsigned long int ptr);
int		process_hex(unsigned int nbr, const char type);
int		process_u(unsigned int nbr);
int		find_u_len(unsigned int nbr);
int		ft_abs(int nbr);
char	*ft_itoa(int nbr);
int		process_di(int nbr);

#endif