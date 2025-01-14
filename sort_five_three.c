/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:49:17 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/14 14:40:32 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (!a || !(a->next))
		return ;
	if (a->nbr > a->next->nbr)
		sa(&a);
}

int	find_min_(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	find_sec_min_(t_stack *stack, int min)
{
	int	sec_min;

	sec_min = 2147483647;
	while (stack)
	{
		if (stack->nbr > min && stack->nbr < sec_min)
			sec_min = stack->nbr;
		stack = stack->next;
	}
	return (sec_min);
}

void	sort_three(t_stack **a)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *a;
	n2 = n1->next;
	n3 = n2->next;
	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	if (n2->nbr < n1->nbr && n2->nbr < n3->nbr && n1->nbr < n3->nbr)
		sa(a);
	else if (n2->nbr < n1->nbr && n2->nbr > n3->nbr && n1->nbr > n3->nbr)
	{
		sa(a);
		rra(a);
	}
	else if (n2->nbr < n1->nbr && n2->nbr < n3->nbr && n1->nbr > n3->nbr)
		ra(a);
	else if (n2->nbr > n1->nbr && n2->nbr > n3->nbr && n1->nbr < n3->nbr)
	{
		sa(a);
		ra(a);
	}
	else if (n2->nbr > n1->nbr && n2->nbr > n3->nbr && n1->nbr > n3->nbr)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nbr == find_min_(*a) || (*a)->nbr == find_sec_min_(*a,
				find_min_(*a)))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	pa(a, b);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	pa(a, b);
}
