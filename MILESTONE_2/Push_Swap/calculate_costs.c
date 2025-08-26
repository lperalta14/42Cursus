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

void	ft_calculatecosts(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*nb;

	nb = *(stack_b->stack);

	while (nb)
	{
		// cost_b
		if (nb->pos <= stack_b->size/ 2)
			nb->cost_b = nb->pos;
		else
			nb->cost_b = -(stack_b->size - nb->pos);

		// cost_a
		if (nb->target <= stack_a->size / 2)
			nb->cost_a = nb->target;
		else
			nb->cost_a = -(stack_a->size - nb->target);

		nb = nb->next;
	}
}
static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_node	*ft_find_cheapest(t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*cheapest;
	long	min_cost;
	long	total;

	tmp = *(stack_b->stack);
	cheapest = tmp;
	min_cost = LONG_MAX;
	while (tmp)
	{
		total = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (total < min_cost)
		{
			min_cost = total;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
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
