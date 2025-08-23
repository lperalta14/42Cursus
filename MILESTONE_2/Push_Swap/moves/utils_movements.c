/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-15 10:05:45 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-15 10:05:45 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pushex3(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_a->size;
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < (size / 2))
	{
		if ((*(stack_a->stack))->index <= size / 2)
		{
			ft_pb(stack_b->stack, stack_a->stack);
			//pushed ++;
		}
		else
			ft_ra(stack_a->stack);
		//i++;
		stack_a->size--;
	}
	while (size > 3)
	{
		ft_pb(stack_b->stack, stack_a->stack);
		stack_a->size--;
	}
}

void	ft_sort_three(t_stack *stack)
{
	t_node *first = *(stack->stack);
	t_node *second = first->next;
	t_node *third = second->next;

	if (first->index > second->index && first->index < third->index)
		ft_sa(stack->stack);
	else if (first->index > second->index && second->index > third->index)
	{
		ft_sa(stack->stack);
		ft_rra(stack->stack);
	}
	else if (first->index > third->index && second->index < third->index)
		ft_ra(stack->stack);
	else if (first->index < second->index && first->index > third->index)
		ft_rra(stack->stack);
	else if (first->index < second->index && second->index > third->index)
	{
		ft_sa(stack->stack);
		ft_ra(stack->stack);
	}
}
void	ft_assignposition(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*ptr;
	int		pos;

	pos = 0;
	ptr = *(stack_a->stack);
	while (ptr)
	{
		ptr->pos = pos;
		pos++;
		ptr = ptr->next;
	}
	pos = 0;
	ptr = *(stack_b->stack);
	while (ptr)
	{
		ptr->pos = pos;
		pos++;
		ptr = ptr->next;
	}
}
t_node	*ft_find_cheapest(t_stack *b)
{
	t_node	*tmp;
	t_node	*cheapest;
	int		min_cost;

	tmp = *(b->stack);
	cheapest = tmp;
	min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < min_cost)
		{
			min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

void	ft_movercheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	cheapest = ft_find_cheapest(stack_b);
	ft_move(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
	ft_pa(stack_a->stack, stack_b->stack);
}
