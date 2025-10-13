/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:15:38 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:15:38 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_checkervalids_bonus(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) < 1)
			ft_error_bonus(NULL, NULL, NULL);
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) && !ft_sign(args[i][j])
				&& !ft_isspace(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_valid_digit_bonus(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (ft_sign(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_dups_bonus(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*now;
	t_node	*dup;

	now = *stack_a->stack;
	while (now)
	{
		dup = now->next;
		while (dup)
		{
			if (dup->value == now->value)
				ft_error_bonus(NULL, stack_a, stack_b);
			dup = dup->next;
		}
		now = now->next;
	}
}
