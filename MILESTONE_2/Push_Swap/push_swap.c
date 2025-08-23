/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:28:46 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/29 19:30:40 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexstack(t_stack *stack_a)
{
	t_node	*ptr;
	t_node	*min_node;
	int		index;
	int		max_index;

	index = 0;
	max_index = stack_a->size;

	while (index < max_index)
	{
		ptr = *(stack_a->stack);
		min_node = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && (!min_node || ptr->value < min_node->value))
				min_node = ptr;
			ptr = ptr->next;
		}
		if (min_node)
			min_node->index = index++;
		printf("%d,%d\n", min_node->value, min_node->index);
	}
}
int	ft_stacksize(t_node *stack)
{
	int	size = 0;

	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
static void	ft_less_than_3(t_stack	*stack_a)
{
	t_node	*first = *(stack_a->stack);
	t_node	*second = first->next;

	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (first->value > second->value)
			ft_sa(stack_a->stack);
		else
			return ;
	}
	else
	{
		
		ft_sort_three(stack_a);
	}
	return ;
}

void	ft_pushswap(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_a->size = ft_stacksize(*(stack_a->stack));
	ft_indexstack(stack_a);
	if (stack_a->size <= 3)
		return (ft_less_than_3(stack_a)); 
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_error(NULL, stack_a);
	stack_b->stack = ft_calloc(sizeof(t_node *), 1);
	if (!stack_b->stack)
		ft_error(NULL, stack_b);
	ft_pushex3(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*(stack_b->stack))
	{
		ft_assignposition(stack_a, stack_b);
		ft_targetpositions(stack_a, stack_b);
		ft_calculatecosts(stack_a, stack_b);
		ft_movercheapest(stack_a, stack_b);
	}
	ft_rotation_a(stack_a);
	ft_free_stack(stack_b);
}
