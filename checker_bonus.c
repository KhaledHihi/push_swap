/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:39:33 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/21 17:02:08 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *list, int len)
{
	if (!list || !list->next)
		return 0;

	int i = 0;
	while(list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}
void	applic_ops(char *op, t_stack **a, t_stack **b)
{
	if (op == "pa\n")
		pa(a, b);
	else if (op == "pb\n")
		pb(a, b);
	else if (op == "sa\n")
		sa(a);
	else if (op == "sb\n")
		sb(b);
	else if (op == "ra\n")
		ra(a);
	else if (op == "rb\n")
		rb(b);
	else if (op == "rra\n")
		rra(b);
	else if (op == "rrb\n")
		rrb(b);
	else
	{
		ft_error(a);
		ft_error(b);
	}
}
void	read_out(t_stack **a,t_stack **b)
{
	char *op;

	op = get_next_line(0);
	while (op)
	{
		applic_ops(op, a, b);
		op = get_next_line(0);
	}
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
	arguments(ac, av, a);
	read_out(a, b);
	if (is_sorted(a, ft_lstsize(a)) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
