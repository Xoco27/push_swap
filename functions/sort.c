/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:37:26 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/21 17:47:16 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
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
	t_stack	*b;

	b = *s;
	if (b->next->content > b->content)
		b = b->next;
	else if (b->next->next->content > b->content)
		b = b->next->next;
	if (b == *s)
		ra(s);
	else if ((*s)->next == b)
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
	int		i;
	int		c;
	t_stack	*t;

	if (!stack)
		return (1);
	*stack = NULL;
	i = 0;
	while (i < argc)
	{
		c = ft_atoi(str[i]);
		t = ft_stacknew(c);
		if (!t)
			return (1);
		if (str[i][0] != 0 && c == 0)
			return (1);
		ft_stackadd(stack, t);
		i++;
	}
	return (0);
}
