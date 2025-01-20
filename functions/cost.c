/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:40:17 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/17 13:41:19 by cfleuret         ###   ########.fr       */
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

int put_cost(t_stack **t, int cheapest)
{
    t_stack *t2 = (*t)->target;
    int i = 0;
    int j = 0;

    if ((*t)->upper)
        i = (*t)->index;
    else
        i = cost(t);
    if (t2->upper)
        j = t2->index;
    else
        j = cost(&t2);
    (*t)->cost = i + j;
    if (i < cheapest)
    {
        cheapest = i;
        (*t)->cheapest = true;
    }
    return (cheapest);
}


void	check_cost_a(t_stack **a)
{
	t_stack	*t;
	int		cheapest;

	t = *a;
	cheapest = 2147483647;
	while (t->next->index != 0)
	{
		if (t->target->index == 0 && t->index == 0)
		{
			t->cost = 0;
			break;
		}
		else
			cheapest = put_cost(&t, cheapest);
		printf("%d\n", t->target->content);
		printf("%d\n", t->cost);
		printf("%s\n", t->cheapest ? "true" : "false");
		t = t->next;
	}
	if (t->index != 0)
		put_cost(&t, cheapest);
	printf("%d\n", t->target->content);
	printf("%d\n", t->cost);
	printf("%s\n", t->cheapest ? "true" : "false");
}
