/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-15 15:25:33 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-15 15:25:33 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ft_rr(stack_a->stack, stack_b->stack); // rotación doble hacia arriba
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		ft_rrr(stack_a->stack, stack_b->stack); // rotación doble hacia abajo
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	ft_rotate_a(t_stack *stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ft_ra(stack_a->stack); 
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		ft_rra(stack_a->stack); 
		(*cost_a)++;
	}
}

static void	ft_rotate_b(t_stack *stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		ft_rb(stack_b->stack);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		ft_rrb(stack_b->stack);
		(*cost_b)++;
	}
}

void	ft_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	ft_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	ft_rotate_a(stack_a, &cost_a);
	ft_rotate_b(stack_b, &cost_b);
	ft_pa(stack_a->stack, stack_b->stack);
}
void	ft_rotation_a(t_stack *stack_a)
{
	int	size;
	int	lowest_pos;
	int	cost_a;

	size = ft_stacksize(*(stack_a->stack));
	if (size < 2)
		return ;
	lowest_pos = ft_find_lowest_index(stack_a);
	if (lowest_pos == 0)
		return ;
	if (lowest_pos <= size / 2)
		cost_a = lowest_pos;
	else
		cost_a = -(size - lowest_pos);

	ft_rotate_a(stack_a, &cost_a);
}
