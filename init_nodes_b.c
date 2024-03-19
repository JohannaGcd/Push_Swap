#include "push_swap.h"

void	set_target_b(t_list *b, t_list *a)
{
	t_list	*temp_a;
	t_list	*target_node;
	long	best_match;

	while (b)
	{
		temp_a = a;
		best_match = LONG_MAX;
		while (a)
		{
			if (temp_a->content > b->content
				&& temp_a->content < best_match)
			{
				target_node = temp_a;
				best_match = temp_a->content;
			}
			temp_a = temp_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min_node(a);
		else
		 	b->target_node = temp_a;
	}
	b = b->next;
	
}

void	init_nodes_b(t_list *b, t_list *a)
{
	set_index(b);
	set_index(a);
	set_target_b(a, b);
}
