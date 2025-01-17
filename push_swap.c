/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:37:46 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/17 11:24:07 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_b(t_stack **b)
{
	if (*b && (*b)->next && (*b)->nbr < (*b)->next->nbr)
		sb(b);
}
int max_index(t_stack **b)
{
    t_stack *move = *b;
    int max = move->nbr;
    int max_pos = 0;
    int current_pos = 0;

    while (move)
    {
        if (move->nbr > max)
        {
            max = move->nbr;
            max_pos = current_pos;
        }
        move = move->next;
        current_pos++;
    }

    return max_pos;
}


void push_to_a(t_stack **a, t_stack **b)
{
	int list_len = ft_lstsize(*b);
    if (!a || !b || !*b)
        return;
    int p;

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
	int list_size = ft_lstsize(a);
	if (list_size <= 100)
		size = list_size / 6;
	else if (list_size <= 500)
		size = list_size / 12;
	else
		size = list_size / 20;
	return (size);
}

void	push_to_b(t_stack **a, t_stack **b, int *arr)
{
	int(size), (i), (list_size);

	i = 0;
	size = check_list_lenght(*a);
	int s = size;
	list_size = ft_lstsize(*a);
	while (*a)
	{
		if ((*a)->nbr <= arr[i])
		{
			pb(a, b);
			rb(b);
			if (i < size)
				i++;
			if (size < list_size - 1)
				size++;
		}
		else if ((*a)->nbr <= arr[size])
		{
			pb(a, b);
			check_b(b);
			if (i < size)
				i++;
			if (size < list_size - 1)
				size++;
		}
		else
			ra(a);
	}
	free(arr);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int list_len = ft_lstsize(*a);
	if (!a || !(*a))
		return ;
	int *arr = list_to_arr(*a);
	push_to_b(a, b, arr);
	push_to_a(a, b);
}
