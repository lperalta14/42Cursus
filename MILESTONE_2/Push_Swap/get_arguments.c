/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 17:26:41 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-07 17:26:41 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_new_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = -1;
	new->pos = -1;
	new->target = -1;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

static void	ft_add_back_node(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_node	*ft_lstlast_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_getnode(t_stack *stack_a, char **split)
{
	int		j;
	long	num;
	t_node	*new_node;

	j = 0;
	while (split[j])
	{
		if (!ft_valid_digit(split[j]))
			ft_error(split, stack_a);
		num = ft_atolints(split[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(split, stack_a);
		new_node = ft_new_node((int)num);
		if (!stack_a->stack)
			ft_error(split, stack_a);
		ft_add_back_node(stack_a->stack, new_node);
		stack_a->size++;
		j++;
	}
	ft_free_split(split);
}

void	ft_get_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;
	int		j;

	split = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (ft_isspace(argv[i][j]))
			j++;
		if (!argv[i][j])
			ft_error(NULL, stack_a);
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error(split, stack_a);
		ft_getnode(stack_a, split);
		i++;
	}
}
