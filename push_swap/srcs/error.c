/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:10:05 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/08 12:32:24 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		if (argv[j][i] == '-')
			i++;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i++]))
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
		}
		j++;
	}
	return (0);
}

int	check_number(char *item)
{
	int	i;

	i = 0;
	if (item[i] == '-')
		i++;
	while (item[i])
	{
		if (!ft_isdigit(item[i++]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	if (ft_atoi(item) > 2147483647 || ft_atoi(item) < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	check_for_repetition(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp_next;

	temp = stack;
	while (temp)
	{
		temp_next = temp->next;
		while (temp_next != NULL)
		{
			if (temp->num == temp_next->num)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			temp_next = temp_next->next;
		}
		temp = temp->next;
	}
	return (0);
}
