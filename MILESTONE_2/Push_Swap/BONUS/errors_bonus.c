/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:11:37 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:11:37 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stack_bonus(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	if (!stack)
		return ;
	temp = *stack->stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(stack->stack);
	stack->stack = NULL;
	free(stack);
}

void	ft_free_split_bonus(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error_bonus(char **split, t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	ft_free_split_bonus(split);
	if (stack_a)
		ft_free_stack_bonus(stack_a);
	if (stack_b)
		ft_free_stack_bonus(stack_b);
	exit(2);
}
