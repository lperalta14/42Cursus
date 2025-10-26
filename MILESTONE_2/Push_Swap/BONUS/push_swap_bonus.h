/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:26:38 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:26:38 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mylib/includes/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	**stack;
	int		size;
}	t_stack;

/* ------------------ ERRORS ------------------ */
void	ft_free_stack_bonus(t_stack *stack);
void	ft_free_split_bonus(char **split);
void	ft_error_bonus(char **split, t_stack *stack_a, t_stack *stack_b);

/* ------------------ GET ARGUMENTS ------------------ */
void	ft_get_arg_bonus(int argc, char **argv, t_stack *a, t_stack *b);
int		ft_checkervalids_bonus(char **args);
int		ft_valid_digit_bonus(char *str);
void	ft_check_dups_bonus(t_stack *stack, t_stack *stack_b);

/* ------------------ UTILS ------------------ */
t_node	*ft_lstlast_node_bonus(t_node *lst);
int		ft_is_sorted_bonus(t_stack *stack_a);
int		ft_stacksize_bonus(t_node *stack);
void	ft_indexstack(t_stack *stack_a);
void	ft_assignposition_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_targetpositions(t_stack *stack_a, t_stack *stack_b);

/* ------------------ PUSH ------------------ */
void	ft_pa_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_pb_bonus(t_stack *stack_a, t_stack *stack_b);

/* ------------------ SWAP ------------------ */
void	ft_swap_bonus(t_node **stack);
void	ft_ss_bonus(t_node **stack_a, t_node **stack_b);

/* ------------------ ROTATE ------------------ */
void	ft_rotate_bonus(t_node **stack);
void	ft_rr_bonus(t_node **stack_a, t_node **stack_b);

/* ------------------ REVERSE ROTATE ------------------ */
void	ft_reverse_rotate_bonus(t_node **stack);
void	ft_rrr_bonus(t_node **stack_a, t_node **stack_b);

#endif
