/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:22 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/22 15:35:24 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **s)
{
	t_stack	*t;

	if (s == NULL || *s == NULL)
		return ;
	t = *s;
	t->index = 0;
	t = t->next;
	while (t != *s)
	{
		t->index = t->prev->index + 1;
		t = t->next;
	}
}

int	best_min(int diff, int temp_diff, t_stack **best_target, t_stack **t)
{
	if (temp_diff < diff)
	{
		diff = temp_diff;
		*best_target = *t;
	}
	return (diff);
}

void	targ_smaller(t_stack **t1, t_stack **t2)
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
		if (t->content < (*t1)->content)
		{
			temp_diff = (*t1)->content - t->content;
			diff = best_min(diff, temp_diff, &best_target, &t);
		}
		t = t->next;
	}
	if (t->content < (*t1)->content)
	{
		temp_diff = (*t1)->content - t->content;
		if (temp_diff < diff)
			best_target = t;
	}
	(*t1)->target = best_target;
}

void	targ_max(t_stack **t1, t_stack **t2)
{
	t_stack	*t;
	int		max;

	t = *t2;
	t = t->next;
	max = t->content;
	while (t->index != 0)
	{
		if (t->content >= max)
		{
			max = t->content;
			(*t1)->target = t;
		}
		t = t->next;
	}
	if (t->content >= max)
	{
		max = t->content;
		(*t1)->target = t;
	}
}

void	set_targ_v1(t_stack **a, t_stack **b)
{
	t_stack	*t1;
	t_stack	*t2;

	t1 = *a;
	t2 = *b;
	while (t1->next->index != 0)
	{
		targ_smaller(&t1, &t2);
		if (t1->target == NULL)
			targ_max(&t1, &t2);
		t1 = t1->next;
	}
	targ_smaller(&t1, &t2);
	if (t1->target == NULL)
		targ_max(&t1, &t2);
}
