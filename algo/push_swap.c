/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:37:46 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/20 14:58:38 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	int	list_len;
	int	p;

	list_len = ft_lstsize(*b);
	if (!a || !b || !*b)
		return ;
	while (list_len > 0)
	{
		p = max_index(b);
		if (p <= list_len / 2)
		{
			while (p-- > 0)
				rb(b);
		}
		else
		{
			while (p++ < list_len)
				rrb(b);
		}
		pa(a, b);
		list_len--;
	}
}

int	check_list_lenght(t_stack *a)
{
	int	size;
	int	list_size;

	list_size = ft_lstsize(a);
	if (list_size <= 100)
		size = list_size / 4;
	else if (list_size <= 500)
		size = list_size / 12;
	else
		size = list_size / 20;
	return (size);
}

void	incre_index(int *i, int *size, int list_size)
{
	if ((*i) < (*size))
		(*i)++;
	if ((*size) < list_size - 1)
		(*size)++;
}

void	push_to_b(t_stack **a, t_stack **b, int *arr, int list_size)
{
	int (size), (i);
	i = 0;
	size = check_list_lenght(*a);
	while (*a)
	{
		if ((*a)->nbr <= arr[i])
		{
			pb(a, b);
			rb(b);
			incre_index(&i, &size, list_size);
		}
		else if ((*a)->nbr <= arr[size])
		{
			pb(a, b);
			check_b(b);
			incre_index(&i, &size, list_size);
		}
		else
			ra(a);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	list_len;
	int	*arr;

	list_len = ft_lstsize(*a);
	if (!a || !(*a))
		return ;
	arr = list_to_arr(*a);
	push_to_b(a, b, arr, list_len);
	free(arr);
	push_to_a(a, b);
}
