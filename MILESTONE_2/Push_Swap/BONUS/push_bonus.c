/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:16:04 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:16:04 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
// Push
static void	ft_push_bonus(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dst;
	*dst = temp;
}

void	ft_pa_bonus(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_bonus(stack_a->stack, stack_b->stack);
	stack_a->size++;
	stack_b->size--;
}

void	ft_pb_bonus(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_bonus(stack_b->stack, stack_a->stack);
	stack_b->size++;
	stack_a->size--;
}

// Swap
void	ft_swap_bonus(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_ss_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_swap_bonus(stack_a);
	ft_swap_bonus(stack_b);
}
