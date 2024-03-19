#include "push_swap.h"

void	init_nodes_b(t_list *b, t_list t_list *a)
{
	set_index(b);
	set_index(a);
	set_target_b(a, b);
}
