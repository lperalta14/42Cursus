/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-11 14:11:17 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-11 14:11:17 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_execute_instruction(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		ft_swap_bonus(a->stack);
	else if (!ft_strncmp(instr, "sb\n", 3))
		ft_swap_bonus(b->stack);
	else if (!ft_strncmp(instr, "ss\n", 3))
		ft_ss_bonus(a->stack, b->stack);
	else if (!ft_strncmp(instr, "pa\n", 3))
		ft_pa_bonus(a, b);
	else if (!ft_strncmp(instr, "pb\n", 3))
		ft_pb_bonus(a, b);
	else if (!ft_strncmp(instr, "ra\n", 3))
		ft_rotate_bonus(a->stack);
	else if (!ft_strncmp(instr, "rb\n", 3))
		ft_rotate_bonus(b->stack);
	else if (!ft_strncmp(instr, "rr\n", 3))
		ft_rr_bonus(a->stack, b->stack);
	else if (!ft_strncmp(instr, "rra\n", 4))
		ft_reverse_rotate_bonus(a->stack);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		ft_reverse_rotate_bonus(b->stack);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		ft_rrr_bonus(a->stack, b->stack);
	else
		return (0);
	return (1);
}

static int	ft_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_execute_instruction(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_is_sorted_bonus(a) && !*(b->stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		ft_error_bonus(NULL, stack_a, stack_b);
	stack_a->stack = ft_calloc(sizeof(t_node *), 1);
	stack_b->stack = ft_calloc(sizeof(t_node *), 1);
	if (!stack_a->stack || !stack_b->stack)
		ft_error_bonus(NULL, stack_a, stack_b);
	stack_a->size = 0;
	stack_b->size = 0;
	ft_get_arg_bonus(argc, argv, stack_a, stack_b);
	ft_check_dups_bonus(stack_a, stack_b);
	if (!ft_checker(stack_a, stack_b))
		write(2, "Error\n", 6);
	ft_free_stack_bonus(stack_a);
	ft_free_stack_bonus(stack_b);
	return (0);
}
