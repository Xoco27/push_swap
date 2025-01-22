/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:40:17 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/22 17:44:11 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(t_stack **b)
{
	if ((*b)->content > (*b)->prev->content)
		sb(b);
}

int	cost(t_stack **t)
{
	t_stack	*t2;
	int		i;

	t2 = *t;
	while (t2->index != 0)
		t2 = t2->next;
	i = t2->prev->index + 1;
	if (stack_len(t) % 2 == 0)
		i -= (*t)->index;
	else
	{
	while (t2->upper == true)
		t2 = t2->next;
	if (t2->content == (*t)->content)
		i -= (*t)->index - 1;
	else
		i -= (*t)->index;
	}
	return (i);
}

int	put_cost(t_stack **t, int cheapest)
{
	t_stack	*t2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t2 = (*t)->target;
	if ((*t)->upper)
		i = (*t)->index;
	else
		i = cost(t);
	if (t2->upper)
		j = t2->index;
	else
		j = cost(&t2);
	(*t)->cost = i + j;
	if (i + j < cheapest)
	{
		cheapest = i + j;
		(*t)->cheapest = true;
	}
	return (cheapest);
}

void	check_cost_a(t_stack **a, t_stack **b)
{
	// t_stack	*t;
	// int		cheapest;

	// t = *a;
	// cheapest = 2147483647;
	// if (t->next == t)
	// {
	// 	t->cheapest = true;
	// 	return ;
	// }
	// while (t->next->index != 0)
	// {
	// 	if (t->target->index == 0 && t->index == 0)
	// 	{
	// 		t->cost = 0;
	// 		t->cheapest = true;
	// 		break ;
	// 	}
	// 	else
	// 		cheapest = put_cost(&t, cheapest);
	// 	//printf("%d %s\n", t->cost, t->cheapest ? "true" : "false");
	// 	t = t->next;
	// }
	// if (t->index != 0)
	// 	put_cost(&t, cheapest);
	// //printf("%d %s\n", t->cost, t->cheapest ? "true" : "false");
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while ((*a))
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
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}
