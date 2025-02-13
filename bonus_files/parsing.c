/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:55 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/28 15:54:35 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	make_list(char *args, t_stack **a, char **arr)
{
	t_stack	*new_node;
	long	value;

	new_node = NULL;
	if (ft_check(args) == 0)
		return (-1);
	value = ft_atoi(args, a, arr);
	if (value > 2147483647 || value < -2147483648)
	{
		free(new_node);
		return (-1);
	}
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
			return (ft_error(a), write(2, "Error\n", 6),
				ft_free_split(split_args), exit(1));
		j = 0;
		while (split_args[j])
		{
			if (make_list(split_args[j], a, split_args) < 0)
				return (ft_error(a), ft_free_split(split_args), write(2,
						"Error\n", 6), exit(1));
			j++;
		}
		ft_free_split(split_args);
	}
	if (ft_duplicate(*a) == 0)
		return (ft_error(a), exit(1));
}
