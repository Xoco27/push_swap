/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:57:56 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/18 14:31:09 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int		content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content);
void	ft_stackadd(t_stack **s, t_stack *new);
void	ft_stackfirst(t_stack **s, t_stack *new);
void	delfirst(t_stack **s);
int		create_stack(int argc, char **str, t_stack **stack);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
int    sort_two(t_stack **s, int cost);
int    sort_three(t_stack **s, int cost);
#endif