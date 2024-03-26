#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "external_lib/src/ft_printf/ft_printf.h"

/*typedef struct	t_list {
	int	value;
	struct t_list *next;
}				t_list;*/

// errors.c
int		error_syntax(char *s);
int		error_duplicate(t_list *a, int n);
void	free_errors(t_list **a);

// stack_init.c
long	ft_atol(const char *s);
void	stack_init(t_list **a, char **argv);
void	append_node(t_list **stack, int n);

// sorting_utils.c
bool	stack_sorted(t_list *stack);
int		length_stack(t_list *stack);
t_list	*find_last_node(t_list *stack);
t_list	*find_max_node(t_list *stack);
t_list	*find_min_node(t_list *stack);
t_list	*get_cheapest(t_list *stack);
void	min_on_top(t_list **stack);

// sorting functions
void	sort_three(t_list **a);
void	big_sort(t_list **a, t_list **b);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	push_a_to_b(t_list **a, t_list **b);
void	push_b_to_a(t_list **b, t_list **a);
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rotate_a_and_rev_b(t_list **a, t_list **b, t_list *cheapest_node);
void	rotate_b_and_rev_a(t_list **a, t_list **b, t_list *cheapest_node);
void    check_for_push(t_list **stack, t_list *top_node, char stack_name);

// Node initialisation 
void	set_target_a(t_list *stack_src, t_list *stack_dest);
void	set_target_b(t_list *b, t_list *a);
void	set_push_cost(t_list *a, t_list *b);
void	set_cheapest(t_list *stack);
void	set_index(t_list *stack);
void	init_nodes_a(t_list *a, t_list *b);
void	init_nodes_b(t_list *b, t_list *a);

// commands
void	swap(t_list **head);
void	sa(t_list **a, bool print);
void	sb(t_list **b, bool print);
void	ss(t_list **a, t_list **b, bool print);

void	rotate(t_list **head);
void	ra(t_list **a, bool print);
void	rb(t_list **b, bool print);
void	rr(t_list **a, t_list **b, bool print);

void	reverse_rotate(t_list **stack);
void	rra(t_list **a, bool print);
void	rrb(t_list **b, bool print);
void	rrr(t_list **a, t_list **b, bool print);

void	push(t_list **src, t_list **dest);
void	pa(t_list **a, t_list **b, bool print);
void	pb(t_list **b, t_list **a, bool print);

// other helper functions
void	print_all(t_list **stack);

#endif
