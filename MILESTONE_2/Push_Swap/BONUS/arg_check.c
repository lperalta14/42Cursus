/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-27 14:52:16 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-27 14:52:16 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_arg_check(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	ft_checkervalids(argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_a->stack = ft_calloc(sizeof(t_node *), 1);
	if (!stack_a->stack)
		ft_error(NULL, stack_a);
	ft_get_arguments(argc, argv, stack_a);
	if (!stack_a)
		ft_error(NULL, NULL);
	ft_check_dups(stack_a);
	return(0);
}

/*int	ft_checkmv_sendft(char	*move)
{
	//hacer una matriz con todos los movimientos y un strmcmp para ver si hay coincidencias o no
	static char	*listmove[] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n"};
	static char	*ftmv[] = {&ft_pa, &ft_pb, &ft_sa, &ft_sb, &ft_ss, &ft_ra, &ft_rb, &ft_rr, &ft_rra};
	int	i;

	while ()
	{
		if (ft_strcmp(move, &listmove[i]))
	}
}*/
int ft_execmv(char *move, t_stack *a, t_stack *b)
{
    if (!ft_strcmp(move, "pa\n"))
        ft_pa(a, b);
    else if (!ft_strcmp(move, "pb\n"))
        ft_pb(a, b);
    else if (!ft_strcmp(move, "sa\n"))
        ft_sa(a);
    else if (!ft_strcmp(move, "sb\n"))
        ft_sb(b);
    else if (!ft_strcmp(move, "ss\n"))
        ft_ss(a, b);
    else if (!ft_strcmp(move, "ra\n"))
        ft_ra(a);
    else if (!ft_strcmp(move, "rb\n"))
        ft_rb(b);
    else if (!ft_strcmp(move, "rr\n"))
        ft_rr(a, b);
    else if (!ft_strcmp(move, "rra\n"))
        ft_rra(a);
    else if (!ft_strcmp(move, "rrb\n"))
        ft_rrb(b);
    else if (!ft_strcmp(move, "rrr\n"))
        ft_rrr(a, b);
    else
        return (0); 
    return (1);
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*move;

	ft_arg_check(argc, argv);
	b = ft_calloc(sizeof(t_stack), 1);
	if (!b)
		ft_error(NULL, a);
	b->stack = ft_calloc(sizeof(t_node *), 1);
	if (!b->stack)
		ft_error(NULL, b);
	while (move = get_next_line(0))
	{
		ft_execmv(move, a, b);
		free(move);
	}
	if(ft_is_sorted(a) && b->size == 0)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	ft_free_stack(a);
	ft_free_stack(b);
	return(0);
}
