#include "push_swap.h"


// for other lgorithm, the turk:
// if stack > 3, push a node to stack b, sortig in descending order
// until stack a has 3 nodes
// check is current node is the biggest,
// if so, rotate the top node to te bottom of the stack
// check if second node is the biggest
// if so, reverse roate the bottom node, t the top of the stack
// check if the top node is bigger than the second
// if so simply swap the two
//
void sort_three(t_list **a)
{
	t_list *max_node = find_max_node(*a); // find the biggest node

	if (*a == max_node) // if biggest node is at the top, simply rotate it to the bottom
		ra(a, true);
	else if ((*a)->next == max_node) // if it is in second position
		rra(a, true); // reverse roate the bottom node to the top of the stack
	if ((*a)->content > (*a)->next->content) // once bottom node is the biggest, check is top node is bigger than second
		sa(a, true); // if so, complete the sorting by swapping the top and second nodes
}

void	sort_four(t_list **a, t_list **b)
{
	min_on_top(a);
	pb(a, b, true);
	sort_three(a);
	pa(a, b, true);
}

void	sort_five(t_list **a, t_list **b)
{
	min_on_top(a);
	pb(a, b, true);
	sort_four(a, b);
}
