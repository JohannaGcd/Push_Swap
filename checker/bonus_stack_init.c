
void	stack_init(t_list **a, char **argv)
{
	int		i;
	long	n;

	n = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

long	ft_atol(const char *s)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	while (s[i] && ((s[i] >= 8 && s[i] <= 13) || s[i] == ' '))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

// Appends n as a new node at the end of the stack.
void	append_node(t_list **stack, int n)
{
	t_list	*new_node;

	if (!stack)
		return ;
	new_node = ft_lstnew(n);
	ft_lstadd_back(stack, new_node);
}
