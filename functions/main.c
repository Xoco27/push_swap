/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:33:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/18 14:35:02 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		cost;
	t_stack	*stack_a;
	//t_stack	*stack_b;

	if (argc < 2)
	{
		ft_printf("\n");
		return (1);
	}
	cost = 0;
	i = 1;
	create_stack(argc, argv, &stack_a);
	if (argc == 3)
		cost = sort_two(&stack_a, cost);
	if (argc == 4)
		cost = sort_three(&stack_a, cost);
	//stack_b = NULL;
	while (i < argc)
	{
		if (!stack_a)
			break;
		ft_printf("%d\n", stack_a->content);
		if (stack_a->next)
			stack_a = stack_a->next;
		else
			break;
		i++;
	}
	ft_printf("%d\n", cost);
	return (0);
}
