/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 17:09:24 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-26 17:09:24 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stack(t_stack *stack)
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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split || split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	ft_error(char **split, t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	ft_free_split(split);
	ft_free_stack(a);
	ft_free_stack(b);
	exit(2);
}
