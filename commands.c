#include "external_lib/src/libft/libft.h"
#include "push_swap.h"

// SWAP OPERATIONS
/* 
 * sa = swaps the positions of the first two nodes in a stack
 * sb = idem, with b 
 * ss = swaps simultaneously the first two nodes of both a and b.
*/

void	swap(t_list **stack)
{
	if (!*stack || !(*stack)->next) // if list is empty or has only one node, exit.
		return ;
	t_list *temp = *stack; // stores the address of the current head in a temp pointer
	*stack = (*stack)->next; // updates head to point to the next node (head -> node 2)
	temp->next = (*stack)->next; // previous head points to the one after the new head (node 1 -> node 3)
	(*stack)->next = temp; // updates next of the previous head to point to the old head (node 2 -> node 1)
}

void	sa(t_list **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}


// ROTATE OPERATIONS
/* 
 * ra = rotates top a node to the bottom and shifts the remaining nodes upwords
 * rb = idem, with b 
 * rr = rotates top nodes of both stacks to the bottom and shifts the remaining nodes upwords
 *
 * rra = brings bottom node to the top of stack a and shifts rets of the nodes downwards
 * rrb = idem, with b
 * rrr = simultaneously reverse rotating both stacks at the same time.
*/ 

void	rotate(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	t_list *last_node = ft_lstlast(*stack);
	
	last_node->next = *stack; // link last node to the first
	*stack = (*stack)->next; // head becomes the second node
	last_node->next->next = NULL; // the node after last node (previous stack) pointer to next becomes NULL 

	last_node = ft_lstlast(*stack);
}

void	ra(t_list **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

// Shifts down all elements of stack by 1. The last node becomes the first.
void	reverse_rotate(t_list **stack) 
{
	if (!*stack || !(*stack)->next)
		return ;
	t_list *second_to_last = *stack;
	t_list *last_node = ft_lstlast(*stack);
	while (second_to_last->next->next != NULL)
	{
		second_to_last = second_to_last->next;

	}
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
		ft_printf("rrb\n");
}

void	print_all(t_list **stack)
{
	t_list	*temp;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}

// PUSH OPERATIONS
/* 
 * pa = pushes the top node of b on top of stack a
 * pb = pushes the top node of a on top of stack b
*/

void	push(t_list **src, t_list **dest)
{
	t_list *push_node; // stores the pointer to the node to be pushed
	if (!*src) // if list is empty, no node to push
		return ;
	t_list *temp_src_head = *src; // store the pointer to the src head
	*src = (*src)->next; // move the head to the second node
	push_node = temp_src_head; // original top node of stack src will be the one to be pushed
	
	if (!*dest)
	{
		*dest = push_node; // if stack dest is empty, set head to push_node
		push_node->next = NULL; // and the next pointer should be NULL;
	}
	else // if the stack is not empty
	{
		t_list *temp_dest_head = *dest; // store the pointer to the first node of dest stack
		*dest = push_node; // the pointer to the head of the destination becomes the second node
		(*dest)->next = temp_dest_head; // set pointer to head of stack to our new pushed node
	}
}

void	pa(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
