/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:03:36 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/17 11:16:42 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_list(char *args, t_stack **a)
{
	t_stack	*new_node;
	long	value;

	if (ft_check(args) == 0)
		return (-1);
	value = ft_atoi(args);
	if (value > 2147483647 || value < -2147483648)
		return (-1);
	new_node = create_node(value);
	add_node_back(a, new_node);
	return (0);
}

void	arguments(int ac, char *av[], t_stack **a)
{
	int		i;
	char	**split_args;
	int		j;

	i = 0;
	while (++i < ac)
	{
		split_args = ft_split(av[i], ' ');
		if (!split_args || !split_args[0])
			return (ft_error(a), write(1, "error\n", 6),
				ft_free_split(split_args), exit(1));
		j = 0;
		while (split_args[j])
		{
			if (make_list(split_args[j], a) < 0)
				return (ft_error(a), ft_free_split(split_args),
				write(2, "error\n", 6), exit(1));
			j++;
		}
		ft_free_split(split_args);
	}
	if (ft_duplicate(*a) == 0)
		return (ft_error(a), exit(1));
	if(ft_lstsize(*a) == 1)
		return (ft_error(a), exit(1));
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (write(1, "error\n", 6), 1);
	arguments(ac, av, &a);
	if (ft_lstsize(a) <= 5)
		sort_five(&a, &b);
	else
		push_swap(&a, &b);
	return(print_node(a), ft_error(&a), ft_error(&b), 0);
}

