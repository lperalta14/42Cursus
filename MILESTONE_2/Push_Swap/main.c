/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 10:55:05 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-13 10:55:05 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;


	if(argc < 2)
		return(0);
	ft_checkervalids(argv);
	stack_a = malloc(sizeof(t_stack));
	if(!stack_a)
		return(0);
	stack_a->stack = ft_calloc(sizeof(t_node *), 1);
	if(!stack_a->stack)
		ft_error(NULL, stack_a);
	ft_get_arguments(argc, argv, stack_a);
	if (!stack_a)
		ft_error(NULL, NULL);
	ft_check_dups(stack_a);
	ft_pushswap(stack_a);
	ft_free_stack(stack_a);
	return (0);
}
