/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:33:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/18 14:35:02 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	if (argc < 1)
	{
		ft_printf("\n");
		return (1);
	}
	create_stack(argc, argv, &stack_a);
	//printf("%d", (*stack_a).content);
	return (0);
}
