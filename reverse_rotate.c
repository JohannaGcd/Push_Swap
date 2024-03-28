#include "push_swap.h"

// Shifts down all elements of stack by 1. The last node becomes the first.
void	reverse_rotate(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	second_to_last = *stack;
	last_node = ft_lstlast(*stack);
	while (second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	second_to_last->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_list **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_list **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, true);
	set_index(*a);
	set_index(*b);
}
