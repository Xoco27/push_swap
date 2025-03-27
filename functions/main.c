/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:33:20 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:20 by cfleuret         ###   ########.fr       */
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

static int	searching(t_stack *t)
{
	int		value;
	t_stack	*i;

	value = t->content;
	i = t->next;
	while (i != t)
	{
		if (i->content == value)
			return (1);
		i = i->next;
	}
	return (0);
}

int	is_duplicate(t_stack **stack)
{
	t_stack	*t;

	t = (*stack)->next;
	while (t != *stack)
	{
		if (searching(t) == 1)
			return (1);
		t = t->next;
	}
	if (searching(t) == 1)
		return (1);
	return (0);
}

static int	checking(int argc, char **argv, t_stack **stack_a, bool str)
{
	if (str == false)
		create_stack(argc, argv, stack_a);
	if (double_check(argc, argv, stack_a, str) == 1)
	{
		free_stack(stack_a);
		return (1);
	}
	if (is_sorted(stack_a) == 0)
	{
		free_stack(stack_a);
		return (0);
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
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (that_one_check(argv) == 1)
			return (1);
		argc = 0;
		while (argv[argc])
			argc++;
		str = true;
		create_stack_str(argc, argv, &stack_a);
	}
	i = checking(argc, argv, &stack_a, str);
	if (i == 1)
		return (1);
	if (str == true)
		ft_free(argv);
	free_stack(&stack_a);
	return (0);
}
