/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:33:20 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/17 13:42:48 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	//int		i;
	t_stack	*stack_a;
	bool	str;

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
	if (str == false)
		create_stack(argc, argv, &stack_a);
	if (is_sorted(&stack_a) == 0)
		return (0);
	if (argc == 2 && str == true)
		sort_two_a(&stack_a);
	else if (argc == 3 && str == true)
		sort_three(&stack_a);
	else if (argc == 3)
		sort_two_a(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else
		sort(&stack_a);
	//i = 0;
	//_stack *stack_b;
	// stack_b = NULL;
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// while (i < argc)
	// {
	// 	if (!stack_b)
	// 		break;
	// 	ft_printf("%d\n", stack_b->content);
	// 	if (stack_b->next)
	// 		stack_b = stack_b->next;
	// 	else
	// 		break;
	// 	i++;
	// }
	return (0);
}
