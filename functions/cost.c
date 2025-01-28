/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:40:17 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/28 17:20:56 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(t_stack **b)
{
	if ((*b)->content > (*b)->prev->content)
		sb(b);
}

int	that_one_check(char **argv)
{
	if (argv == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

void	check_cost_a(t_stack **a, t_stack **b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (((*a)->next->index != 0))
	{
		(*a)->cost = (*a)->index;
		if (!((*a)->upper))
			(*a)->cost = len_a - ((*a)->index);
		if ((*a)->target->upper)
			(*a)->cost += (*a)->target->index;
		else
			(*a)->cost += len_b - ((*a)->target->index);
		(*a) = (*a)->next;
	}
	(*a)->cost = (*a)->index;
	if (!((*a)->upper))
		(*a)->cost = len_a - ((*a)->index);
	if ((*a)->target->upper)
		(*a)->cost += (*a)->target->index;
	else
		(*a)->cost += len_b - ((*a)->target->index);
	(*a) = (*a)->next;
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest;

	if (!stack)
		return ;
	cheapest_value = 2147483647;
	while (stack->next->index != 0)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	if (stack->cost < cheapest_value)
	{
		cheapest_value = stack->cost;
		cheapest = stack;
	}
	stack = stack->next;
	cheapest->cheapest = true;
}
