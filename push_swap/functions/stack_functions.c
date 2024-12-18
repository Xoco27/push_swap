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
		return ;
	}
	p = *s;
	while (p->next != NULL || p->next->content != (*s)->content)
		p = p->next;
	new->next = *s;
    new->prev = p;
    p->next = new;
    (*s)->prev = new;
}

void	delfirst(t_stack *s)
{
	t_stack	*p;

	p = s->prev;
	p->next = s->next;
	p = s->next;
	p->prev = s->prev;
	//free(s->content);
	free(s);
}

int	create_stack(int argc, char **str, t_stack **stack)
{
	int	i;
	int	c;
	t_stack	*t;

	i = 1;
	while(i < argc)
	{
		c = ft_atoi(str[i]);
		ft_printf("%d\n", c);
		if (c == 0 && str[i][0] != 0)
			return (1);
		if (stack == NULL)
			*stack = ft_stacknew(c);
		else
		{
			t = ft_stacknew(c);
			ft_stackadd(stack, t);
		}
		i++;
	}
	return (0);
}
