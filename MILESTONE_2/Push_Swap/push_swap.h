
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdlib.h>
# include "my_lib/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef	struct s_stack
{
	t_node			**stack;
	int				size;
}	t_stack;

void	ft_get_arguments(int argc, char **argv, t_stack *stack_a);
t_node	*ft_new_node(int num);
t_node	*ft_lstlast_node(t_node *lst);
void	ft_getnode(t_stack *stack_a, char **split);
void	ft_checkervalids(char **args);
int		ft_valid_digit(char *str);
void	ft_pushswap(t_stack *stack_a);
void	ft_free_stack(t_stack *stack);
void	ft_free_split(char **split);
void	ft_error(char **split, t_stack *stack);
void	ft_check_dups(t_stack *stack);
int		ft_stacksize(t_node *stack);
void	ft_indexstack(t_stack *stack_a);

void	ft_swap(t_node **stack);
void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);

void	ft_push(t_node **dst, t_node **src);
void	ft_pa(t_node **dst, t_node **src);
void	ft_pb(t_node **dst, t_node **src);

void	ft_rotate(t_node **stack);
void	ft_ra(t_node **stack_a);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);

void	ft_reverse_rotate(t_node **stack);
void	ft_rra(t_node **stack_a);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);

void	ft_pushex3(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_three(t_stack *stack);
void	ft_assignposition(t_stack *stack_a, t_stack *stack_b);
void	ft_targetpositions(t_stack *a, t_stack *b);
void	ft_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
t_node	*ft_find_cheapest(t_stack *b);
void	ft_movercheapest(t_stack *stack_a, t_stack *stack_b);
void	ft_rotation_a(t_stack *stack_a);

void	ft_calculatecosts(t_stack *a, t_stack *b);
int		ft_find_lowest_index(t_stack *stack_a);
#endif
