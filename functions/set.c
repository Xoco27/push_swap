/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:22 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/17 14:37:09 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **s)
{
	t_stack	*t;

	if (s == NULL || *s == NULL)
		return ;
	t = *s;
	while (t->next != *s)
	{
		t->next->index = t->index + 1;
		t = t->next;
	}
}

void	set_med(t_stack **s, int len)
{
	t_stack	*t;

	if (s == NULL || *s == NULL)
		return ;
	t = *s;
	while (t->next->content != (*s)->content)
	{
		if (t->index < (len / 2))
			t->upper = true;
		else
			t->upper = false;
		t = t->next;
	}
}

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

void	set_targ_v1(t_stack **a, t_stack **b)
{
	t_stack	*t1;
	t_stack	*t2;

	t1 = *a;
	t2 = *b;
	while (t1->next->index != 0)
	{
		targ(&t1, &t2);
		if (t1->target == NULL)
		{
			targ_max(&t1, &t2);
		}
		t1 = t1->next;
	}
	targ(&t1, &t2);
	if (t1->target == NULL)
	{
		targ_max(&t1, &t2);
	}
}
