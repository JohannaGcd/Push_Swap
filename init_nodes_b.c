#include "push_swap.h"

void	set_target_b(t_list *dest, t_list *src)
{
	t_list	*temp_dest;
	t_list	*target_node;
	long	best_match;

	while (src)
	{
		temp_dest = dest;
		best_match = LONG_MAX;
		while (dest)
		{
			if (temp_dest->content > src->content
				&& temp_dest->content < best_match)
			{
				target_node = temp_dest;
				best_match = temp_dest->content;
			}
			temp_dest = temp_dest->next;
		}
		if (best_match == LONG_MAX)
			src->target_node = find_min_node(dest);
		else
		 	src->target_node = temp_dest;
	}
	src = src->next;
	
}

void	init_nodes_b(t_list *b, t_list *a)
{
	set_index(b);
	set_index(a);
	set_target_b(a, b);
}
