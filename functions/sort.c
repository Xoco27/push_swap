/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:37:26 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/30 12:43:08 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->prev)
		return ;
	*a = (*a)->prev;
	if (!b || !*b || !(*b)->prev)
		return ;
	*b = (*b)->prev;
	set_pos(a);
	set_pos(b);
	ft_printf("rrr\n");
}

void	sort_two_a(t_stack **a)
{
	if ((*a)->content > (*a)->prev->content)
		sa(a);
}

void	sort_three(t_stack **s)
{
	t_stack	*t;

	t = *s;
	if (t->next->content > t->content)
		t = t->next;
	else if (t->next->next->content > t->content)
		t = t->next->next;
	if (t == *s)
		ra(s);
	else if ((*s)->next == t)
		rra(s);
	if ((*s)->content > (*s)->next->content)
		sa(s);
}

int	is_sorted(t_stack **s)
{
	t_stack	*tmp;
	int		first;

	tmp = *s;
	first = tmp->content;
	tmp = tmp->next;
	while (tmp->content != first)
	{
		if ((tmp->content > tmp->next->content && tmp->next->content != first)
			|| (tmp->content < tmp->prev->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	create_stack_str(int argc, char **str, t_stack **stack)
{
	int			i;
	long		c;
	t_stack		*t;

	if (!stack)
		return (1);
	*stack = NULL;
	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(str[i], "0", 2) == 0)
			c = 0;
		else
		{
			c = ft_atol(str[i]);
			if ((str[i][0] != '\0' && c == 0) || c > INT_MAX || c < INT_MIN)
				return (1);
		}
		t = ft_stacknew((int)c);
		if (!t)
			return (1);
		ft_stackadd(stack, t);
		i++;
	}
	return (0);
}
