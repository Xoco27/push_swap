/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:34:34 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/18 14:48:39 by cfleuret         ###   ########.fr       */
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

void	delfirst(t_stack **s)
{
	t_stack	*p;
	t_stack *t;

	if (!s || !*s)
        return;
    if ((*s)->next == *s)
    {
        free(*s);
        *s = NULL;
        return;
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
	int	i;
	int	c;
	t_stack	*t;

	if (!stack)
		return (1);
	*stack = NULL;
	i = 1;
	while(i < argc)
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
