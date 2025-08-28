/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 10:57:39 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-13 10:57:39 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast_node(*stack);
	last->next = first;
}

void	ft_ra(t_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
