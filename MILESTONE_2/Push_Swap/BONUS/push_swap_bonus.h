/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-28 16:41:35 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-28 16:41:35 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include "../my_lib/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*stack;
	int				size;
}	t_stack;

void	ft_free_stack(t_stack *stack);
void	ft_free_split(char **split);
void	ft_error(char **split, t_stack *stack);

void	ft_get_arguments(int argc, char **argv, t_stack *stack);
t_node	*ft_lstlast_node(t_node *lst);
void	ft_getnode(t_stack *stack, char **split);

void	ft_checkervalids(char **args);
int		ft_valid_digit(char *str);
void	ft_check_dups(t_stack *stack);
int		ft_is_sorted(t_stack *a);
//void	ft_swap(t_node **stack);
void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);

//void	ft_push(t_node **dst, t_node **src);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

//void	ft_rotate(t_node **stack);
void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);

//void	ft_reverse_rotate(t_node **stack);
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);

#endif
