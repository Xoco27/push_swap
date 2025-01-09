/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:32:11 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/07 17:32:11 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    pa(t_stack **a, t_stack **b)
{
    t_stack *t;

    if (a == NULL || *a == NULL)
        return ;
    t = ft_stacknew((*a)->content);
    if (t == NULL)
        return ;
    ft_stackfirst(b, t);
    delfirst(a);
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *t;

    if (b == NULL || *b == NULL)
        return ;
    t = ft_stacknew((*b)->content);
    if (t == NULL)
        return ;
    ft_stackfirst(a, t);
    delfirst(b);
}

void    sa(t_stack **a)
{
    int n;
    t_stack *t;

    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return ;
    t = *a;
    n = t->content;
    t->content = t->next->content;
    t->next->content = n;
}

void    sb(t_stack **b)
{
    int n;
    t_stack *t;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    t = *b;
    n = t->content;
    t->content = t->next->content;
    t->next->content = n;
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);   
}