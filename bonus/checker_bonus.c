/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:39:33 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/24 23:54:25 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	make_list(char *args, t_stack **a)
{
	t_stack	*new_node;
	long	value;

	new_node = NULL;
	if (ft_check(args) == 0)
		return (-1);
	value = ft_atoi(args);
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
			if (make_list(split_args[j], a) < 0)
				return (ft_error(a), ft_free_split(split_args), write(2,
						"Error\n", 6), exit(1));
			j++;
		}
		ft_free_split(split_args);
	}
	if (ft_duplicate(*a) == 0)
		return (ft_error(a), exit(1));
	if (ft_lstsize(*a) == 1)
		return (ft_error(a), exit(0));
}

int	is_sorted(t_stack *list)
{
	if (!list || !list->next)
		return 0;

	while(list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}
int	applic_ops(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else
		return 1;
	return 0;
}

void	read_out(t_stack **a,t_stack **b)
{
	char *op;

	op = get_next_line(0);
	while (op)
	{
		if (applic_ops(op, a, b) == 1)
		{
			free(op);
			ft_error(a);
			ft_error(b);
			write(2, "Error\n", 6);
			break;
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
}
int main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (1);
	arguments(ac, av, &a);
	read_out(&a, &b);
	if (is_sorted(a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	ft_error(&a);
	ft_error(&b);
}
