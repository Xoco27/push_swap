/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:20:25 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:25 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	targ(t_stack **t1, t_stack **t2)
{
	t_stack	*t;
	int		i;

	t = *t2;
	while (t->next->index != 0)
	{
		i = (*t1)->content - 1;
		while (i >= t->content)
		{
			if (t->content == i)
				(*t1)->target = t;
			i--;
		}
		t = t->next;
	}
	i = (*t1)->content - 1;
	while (i >= t->content)
	{
		if (t->content == i)
			(*t1)->target = t;
		i--;
	}
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
	if (t->content > max)
	{
		max = t->content;
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
		targ(&t1, &t2);
		if (t1->target == NULL)
			targ_max(&t1, &t2);
		t1 = t1->next;
	}
	targ(&t1, &t2);
	if (t1->target == NULL)
		targ_max(&t1, &t2);
}