/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:27 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/09 16:24:27 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    ra(t_stack **a)
{
    if (!a || !*a || !(*a)->next)
        return ;

    *a = (*a)->next;
}

void    rb(t_stack **b)
{
    if (!b || !*b || !(*b)->next)
        return ;

    *b = (*b)->next;
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}

void    rra(t_stack **a)
{
    if (!a || !*a || !(*a)->prev)
        return ;

    *a = (*a)->prev;
}

void    rrb(t_stack **b)
{
    if (!b || !*b || !(*b)->prev)
        return ;

    *b = (*b)->prev;
}