/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:37:26 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/09 16:37:26 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}

int    sort_two(t_stack **s, int cost)
{
    if ((*s)->content > (*s)->prev->content)
        sa(s);
    return (cost++);
}

int    sort_three(t_stack **s, int cost)
{
    if (((*s)->content > (*s)->prev->content && (*s)->content > (*s)->next->content
    && (*s)->prev->content < (*s)->next->content)
    || ((*s)->content > (*s)->prev->content && (*s)->content < (*s)->next->content
    && (*s)->prev->content < (*s)->next->content))
    {
        rra(s);
        cost++;
    }
    if (((*s)->content < (*s)->prev->content && (*s)->content < (*s)->next->content
    && (*s)->prev->content < (*s)->next->content)
    || ((*s)->content < (*s)->prev->content && (*s)->content > (*s)->next->content
    && (*s)->prev->content > (*s)->next->content))
    {
        sa(s);
        cost++;
    }
    if ((*s)->content > (*s)->prev->content && (*s)->content > (*s)->next->content
    && (*s)->prev->content > (*s)->next->content)
    {
        ra(s);
        cost++;
    }
    return (cost);
}