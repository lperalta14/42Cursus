/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   arg_check_bonus.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lperalta <lperalta@student.42.fr>		  #+#  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025-08-27 14:52:16 by lperalta		  #+#	#+#			 */
/*   Updated: 2025-08-27 14:52:16 by lperalta		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_arg_check(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	ft_checkervalids(argv);
	a = ft_calloc(sizeof(t_stack), 1);
	if (!a)
		ft_error(NULL, NULL, NULL);
	b = ft_calloc(sizeof(t_stack), 1);
	if (!b)
		ft_error(NULL, a, NULL);
	ft_get_arguments(argc, argv, a);
	if (!a)
		ft_error(NULL, NULL, b);
	ft_check_dups(a);
	return (0);
}

int	ft_is_sorted(t_stack *stack_a)
{
	t_node	*this;

	this = stack_a->stack;
	while (this->next)
	{
		if (this->value > this->next->value)
			return (0);
		this = this->next;
	}
	return (1);
}

int	ft_execmv(char *move, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(move, "pa\n"))
		ft_pa(*a, *b);
	else if (!ft_strcmp(move, "pb\n"))
		ft_pb(*a, *b);
	else if (!ft_strcmp(move, "sa\n"))
		ft_sa(a->stack);
	else if (!ft_strcmp(move, "sb\n"))
		ft_sb(b->stack);
	else if (!ft_strcmp(move, "ss\n"))
		ft_ss(a->stack, b->stack);
	else if (!ft_strcmp(move, "ra\n"))
		ft_ra(a->stack);
	else if (!ft_strcmp(move, "rb\n"))
		ft_rb(b->stack);
	else if (!ft_strcmp(move, "rr\n"))
		ft_rr(a->stack, b->stack);
	else if (!ft_strcmp(move, "rra\n"))
		ft_rra(a->stack);
	else if (!ft_strcmp(move, "rrb\n"))
		ft_rrb(b->stack);
	else if (!ft_strcmp(move, "rrr\n"))
		ft_rrr(a->stack, b->stack);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*move;

	a = NULL;
	ft_arg_check(argc, argv);
	b = ft_calloc(sizeof(t_stack), 1);
	if (!b)
		ft_error(NULL, a, NULL);
	move = get_next_line(0);
	while (move)
	{
		if (!ft_execmv(move, a, b))
			ft_error(NULL, a, b);
		free(move);
		move = get_next_line(0);
	}
	if (ft_is_sorted(a) && b->size == 0)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
