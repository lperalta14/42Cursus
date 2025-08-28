/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 10:57:27 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-13 10:57:27 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_push(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dst;
	*dst = temp;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	**a;
	t_node	**b;

	a = a->stack;
	b = b->stack;
	ft_push(a, b);
	write(1, "pa\n", 3);
	a->size ++;
	b->size --;
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	**a;
	t_node	**b;

	a = a->stack;
	b = b->stack;
	ft_push(b, a);
	write(1, "pb\n", 3);
	b->size ++;
	a->size --;
}
