/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:34:34 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/27 15:16:57 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*c;

	c = malloc(sizeof(*c));
	if (c == NULL)
		return (NULL);
	c->content = content;
	c->next = NULL;
	c->prev = NULL;
	c->index = 0;
	c->cost = 0;
	c->upper = false;
	c->cheapest = false;
	c->target = NULL;
	return (c);
}

void	ft_stackadd(t_stack **s, t_stack *new)
{
	t_stack	*p;

	if (new == NULL || s == NULL)
		return ;
	if (*s == NULL)
	{
		*s = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	p = (*s)->prev;
	new->next = *s;
	new->prev = p;
	p->next = new;
	(*s)->prev = new;
}

void	ft_stackfirst(t_stack **s, t_stack *new)
{
	t_stack	*p;

	if (new == NULL || s == NULL)
		return ;
	if (*s == NULL)
	{
		*s = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	p = (*s)->prev;
	new->next = *s;
	new->prev = p;
	p->next = new;
	(*s)->prev = new;
	*s = new;
}

void	delfirst(t_stack **s)
{
	t_stack	*p;
	t_stack	*t;

	if (!s || !*s)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	p = (*s)->prev;
	p->next = (*s)->next;
	(*s)->next->prev = p;
	t = *s;
	*s = (*s)->next;
	free(t);
}

int	create_stack(int argc, char **str, t_stack **stack)
{
	int		i;
	int		c;
	t_stack	*t;

	if (!stack)
		return (1);
	*stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(str[i], "0", 2) == 0)
			c = 0;
		else
		{
			c = ft_atoi(str[i]);
			if ((str[i][0] != '\0' && c == 0))
				return (1);
		}
		t = ft_stacknew(c);
		if (!t)
			return (1);
		ft_stackadd(stack, t);
		i++;
	}
	return (0);
}
