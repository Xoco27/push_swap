/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:57:56 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/17 13:42:15 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				cost;
	bool			upper;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content);
void	ft_stackadd(t_stack **s, t_stack *new);
void	ft_stackfirst(t_stack **s, t_stack *new);
void	delfirst(t_stack **s);
int		create_stack(int argc, char **str, t_stack **stack);
int		create_stack_str(int argc, char **str, t_stack **stack);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_two_a(t_stack **s);
void	sort_two_b(t_stack **b);
void	sort_three(t_stack **s);
int		is_sorted(t_stack **s);
void	set_med(t_stack **s, int len);
void	set_pos(t_stack **s);
int		stack_len(t_stack **s);
void	sort(t_stack **a);
void	set_targ_v1(t_stack **a, t_stack **b);
void	check_cost_a(t_stack **a);
#endif
