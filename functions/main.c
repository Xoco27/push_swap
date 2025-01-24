/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:33:20 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/24 14:21:38 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **s)
{
	while (*s)
	{
		delfirst(s);
	}
}

int	is_duplicate(t_stack **stack)
{
	int		value;
	t_stack	*t;
	t_stack	*i;
	
	t = (*stack)->next;
	i = t;
	while (t != *stack)
	{
		value = t->content;
		while (i != stack)
		{
			if (i->content == value)
				return (1);
			i = i->next;
		}
		if (i->content == value)
			return (1);
		i = i->next;
		t = t->next;
	}
	value = t->content;
	while (i != stack)
	{
		if (i->content == value)
			return (1);
		i = i->next;
	}
	if (i->content == value)
		return (1);
	i = i->next;
	return (0);
}

int	checking(int argc, char **argv, t_stack **stack_a, bool str)
{
	if (str == false)
		create_stack(argc, argv, stack_a);
	if (is_duplicate(stack_a))
	{
		free_stack(stack_a);
		return (1);
	}
	if (is_sorted(stack_a) == 0)
	{
		free_stack(stack_a);
		return (1);
	}
	if (argc == 2 && str == true)
		sort_two_a(stack_a);
	else if (argc == 3 && str == true)
		sort_three(stack_a);
	else if (argc == 3)
		sort_two_a(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else
		sort(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	bool	str;
	int		i;

	str = false;
	if (argc < 2)
	{
		ft_printf("\n");
		return (1);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		str = true;
		create_stack_str(argc, argv, &stack_a);
	}
	i = checking(argc, argv, &stack_a, str);
	if (i == 1)
		return (0);
	free_stack(&stack_a);
	i = 0;
	while (i < argc - 1)
	{
		if (!stack_a)
			break ;
		ft_printf("%d\n", stack_a->content);
		if (stack_a->next)
			stack_a = stack_a->next;
		else
			break ;
		i++;
	}
	return (0);
}
