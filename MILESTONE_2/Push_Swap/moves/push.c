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

#include "../push_swap.h"

void	ft_push(t_node **dst, t_node **src)
{
	t_node *temp;

	if (!src || !*src)
		return;
	temp = *src;
	*src = temp->next;
	temp->next = *dst;
	*dst = temp;
}

void	ft_pa(t_node **dst, t_node **src)
{
	ft_push(dst, src);
	write(1, "pa\n", 3);
}
void	ft_pb(t_node **dst, t_node **src)
{
	ft_push(dst, src);
	write(1, "pb\n", 3);
}
