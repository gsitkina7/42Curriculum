/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:21:23 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/18 11:43:29 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*split_list(char **list)
{
	int		i;
	t_stack	*first;
	t_stack	*temp;

	i = 0;
	first = NULL;
	while (list[i] != NULL)
	{
		if (check_number(list[i]))
			return (NULL);
		if (i == 0)
		{
			first = new_element(ft_atoi(list[i]));
			first->next = temp;
			temp = first;
			free(list[i]);
		}
		else
		{
			temp->next = new_element(ft_atoi(list[i]));
			temp = temp->next;
			free(list[i]);
		}
		i++;
	}
	temp->next = NULL;
	free(list);
	return (first);
}

static t_stack	*create_stack(int ac, char **av)
{
	t_stack	*temp;
	t_stack	*first;
	int		i;

	i = 0;
	first = NULL;
	while (++i < ac)
	{
		if (check_number(av[i]))
			return (NULL);
		if (i == 1)
		{
			first = new_element(ft_atoi(av[i]));
			first->next = temp;
			temp = first;
		}
		else
		{
			temp->next = new_element(ft_atoi(av[i]));
			temp = temp->next;
		}
	}
	temp->next = NULL;
	return (first);
}

t_stack	*initialize_stack(int ac, char **av)
{
	if (ac == 2)
		return (split_list(ft_split(av[1], ' ')));
	else
		return (create_stack(ac, av));
}
