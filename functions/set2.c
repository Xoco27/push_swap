/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:20:25 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/21 15:32:45 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best(int diff, int temp_diff, t_stack **best_target, t_stack **t)
{
	if (temp_diff < diff)
	{
		diff = temp_diff;
		*best_target = *t;
	}
	return (diff);
}

void	targ_bigger(t_stack **t1, t_stack **t2)
{
	t_stack	*t;
	t_stack	*best_target;
	int		diff;
	int		temp_diff;

	t = *t2;
	diff = 2147483647;
	best_target = NULL;

	while (t->next->index != 0)
	{
		if (t->content > (*t1)->content)
		{
			temp_diff = t->content - (*t1)->content;
			diff = best(diff, temp_diff, &best_target, &t);
		}
		t = t->next;
	}
	if (t->content > (*t1)->content)
	{
		temp_diff = t->content - (*t1)->content;
		if (temp_diff < diff)
			best_target = t;
	}
	(*t1)->target = best_target;
}

void	targ_min(t_stack **t1, t_stack **t2)
{
	t_stack	*t;
	int		min;

	t = *t2;
	t = t->next;
	min = t->content;
	while (t->index != 0)
	{
		if (t->content <= min)
		{
			min = t->content;
			(*t1)->target = t;
		}
		t = t->next;
	}
	if (t->content <= min)
	{
		min = t->content;
		(*t1)->target = t;
	}
}

void	set_targ_v2(t_stack **a, t_stack **b)
{
	t_stack	*t1;
	t_stack	*t2;

	t1 = *a;
	t2 = *b;
	while (t2->next->index != 0)
	{
		targ_bigger(&t2, &t1);
		if (t2->target == NULL)
			targ_min(&t2, &t1);
		t2 = t2->next;
	}
	targ_bigger(&t2, &t1);
	if (t2->target == NULL)
		targ_min(&t2, &t1);
}
