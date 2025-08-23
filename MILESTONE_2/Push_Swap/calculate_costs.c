/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-14 16:21:52 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-14 16:21:52 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculatecosts(t_stack *a, t_stack *b)
{
	t_node *current;
	int size_a = ft_stacksize(*a->stack);
	int size_b = ft_stacksize(*b->stack);

	current = *b->stack;
	while (current)
	{
		// cost_b
		if (current->pos <= size_b / 2)
			current->cost_b = current->pos;
		else
			current->cost_b = (current->pos - size_b);

		// cost_a
		if (current->target <= size_a / 2)
			current->cost_a = current->target;
		else
			current->cost_a = (current->target - size_a);

		current = current->next;
	}
}
int	ft_find_lowest_index(t_stack *stack_a)
{
	t_node	*current;
	int		lowest_index;
	int		lowest_pos;
	int		pos;

	current = *(stack_a->stack);
	lowest_index = current->index;
	lowest_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (lowest_pos);
}
