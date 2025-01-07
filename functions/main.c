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
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 1)
	{
		ft_printf("\n");
		return (1);
	}
	i = 1;
	create_stack(argc, argv, &stack_a);
	//stack_b = stack_a;
	sa(&stack_a, &stack_b);
	while (i < argc)
	{
		printf("%d\n", stack_a->content);
		if (stack_a->next)
			stack_a = stack_a->next;
		else
			break;
		i++;
	}
	while (i < argc)
	{
		printf("%d\n", stack_b->content);
		if (stack_b->next)
			stack_b = stack_b->next;
		else
			break;
		i++;
	}
	return (0);
}
