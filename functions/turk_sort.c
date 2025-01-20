/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:43 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/17 13:41:59 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack **s)
{
	int		i;
	t_stack	*t;

	i = 1;
	t = *s;
	t = t->next;
	while (t != *s)
	{
		i++;
		t = t->next;
	}
	return (i);
}

void	set_stack(t_stack **a, t_stack **b)
{
	// pb(a, b);
	set_pos(a);
	set_pos(b);
	set_med(a, stack_len(a));
	set_med(b, stack_len(b));
	set_targ_v1(a, b);
	check_cost_a(a);
}

void	sort(t_stack **a)
{
	int		len;
	t_stack	*b;

	b = NULL;
	len = stack_len(a);
	pb(a, &b);
	len--;
	if (len > 3)
	{
		pb(a, &b);
		sort_two_b(&b);
		len--;
	}
	else
		sort_three(a);
	while (len > 3)
	{
		set_stack(a, &b);
		len--;
	}
}
