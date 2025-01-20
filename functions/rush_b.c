/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:14:56 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/20 18:14:56 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *a;
	while (t->cheapest != true)
		t = t->prev;
	while (t->index != 0)
	{
		if (t->upper == true)
			ra(a);
		else
			rra(a);
	}
	while (t->target->index != 0)
	{
		if (t->upper == true)
			rb(b);
		else
			rrb(b);
	}
	pb(a, b);
}