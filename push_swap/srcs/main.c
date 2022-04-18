/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:57:01 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/18 11:43:40 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	if (argc >= 2)
		a = initialize_stack(argc, argv);
	if (a && !check_for_repetition(a) && (ft_lstsize(a) > 1))
	{
		b = NULL;
		if (ft_lstsize(a) <= 3)
			sort_three(&a);
		else if (ft_lstsize(a) <= 5)
			sort_five(&a, &b);
		else
			sort_big(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
