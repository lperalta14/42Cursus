/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:11:25 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:11:25 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// Devuelve el último nodo de la lista
t_node	*ft_lstlast_node_bonus(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Obtiene el tamaño de la lista
int	ft_stacksize_bonus(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// Asigna la posición de cada nodo en la lista
void	ft_assignposition_bonus(t_stack *stack_a, t_stack *stack_b)
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

int	ft_is_sorted_bonus(t_stack *stack_a)
{
	t_node	*this;

	if (!*(stack_a->stack))
		return (0);
	this = *(stack_a->stack);
	while (this->next)
	{
		if (this->value > this->next->value)
			return (0);
		this = this->next;
	}
	return (1);
}
