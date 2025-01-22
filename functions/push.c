/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:14:56 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/22 17:33:23 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_first_part(t_stack **a, t_stack **b, t_stack *t)
{
	while (t->index != 0)
	{
		if (t->upper == true)
			ra(a);
		else
			rra(a);
	}
	while (t->target->index != 0)
	{
		if (t->target->upper == true)
			rb(b);
		else
			rrb(b);
	}
}

void	rotate_second_part(t_stack **a, t_stack **b, t_stack *t)
{
	while (t->index != 0)
	{
		if (t->upper == true)
			rb(b);
		else
			rrb(b);
	}
	while (t->target->index != 0)
	{
		if (t->target->upper == true)
			ra(a);
		else
			rra(a);
	}
}

void	push_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *a;
	while (t->cheapest != true)
	{
		t = t->prev;
		printf("%d\n", t->content);
	}
	while (t->index != 0 && t->target->index != 0)
	{
		if (t->upper == true && t->target->upper == true)
			rr(a, b);
		else if (t->upper == false && t->target->upper == false)
			rrr(a, b);
		else
			break ;
	}
	rotate_first_part(a, b, t);
	pb(a, b);
}

void	push_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *b;
	while (t->cheapest != true)
		t = t->prev;
	while (t->index != 0 && t->target->index != 0)
	{
		if (t->upper == true && t->target->upper == true)
			rr(a, b);
		else if (t->upper == false && t->target->upper == false)
			rrr(a, b);
		else
			break ;
	}
	rotate_second_part(a, b, t);
	pa(a, b);
}
