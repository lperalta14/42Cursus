/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-15 15:15:39 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-15 15:15:39 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*ft_find_target_node(t_stack *stack_a, t_node *node_b)
{
	t_node	*node_a;
	t_node	*target_node;
	long	best_index;

	best_index = LONG_MAX;
	target_node = NULL;
	node_a = *(stack_a->stack);
	while (node_a)
	{
		if (node_a->index > node_b->index && node_a->index < best_index)
		{
			best_index = node_a->index;
			target_node = node_a;
		}
		node_a = node_a->next;
	}
	return (target_node);
}

static t_node	*ft_find_min_node(t_stack *stack_a)
{
	t_node	*node_a;
	t_node	*target_node;
	long	best_index;

	best_index = LONG_MAX;
	target_node = NULL;
	node_a = *(stack_a->stack);
	while (node_a)
	{
		if (node_a->index < best_index)
		{
			best_index = node_a->index;
			target_node = node_a;
		}
		node_a = node_a->next;
	}
	return (target_node);
}

void	ft_targetpositions(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*target_node;

	node_b = *(stack_b->stack);
	while (node_b)
	{
		target_node = ft_find_target_node(stack_a, node_b);
		if (!target_node)
			target_node = ft_find_min_node(stack_a);
		node_b->target = target_node->pos;
		node_b = node_b->next;
	}
}
