/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:37:46 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/16 22:27:07 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_b(t_stack **b)
{
	if (*b && (*b)->next && (*b)->nbr < (*b)->next->nbr)
		sb(b);
}
int	max_index(t_stack *b)
{
	int p = 0;
	t_stack *move = b;
	int max = b->nbr;
	while(move)
	{
		if(move->nbr > max)
		{
			max = move->nbr;
		}
		move = move->next;
	}
	move = b;
	while(move)
	{
		if(move->nbr == max)
			break;
		p++;
	}
	return (p);
}

void push_to_a(t_stack **a, t_stack **b)
{
    int list_len;
    t_stack *move;
	int pos;
    if (!a || !b || !*b)
        return;

    list_len = ft_lstsize(*b);

    while (list_len > 0)
    {
		pos = max_index(*b);
		if (pos <= list_len / 2)
        {
            while (pos-- > 0)
                rb(b);
        }
        else
        {
            pos = list_len - pos;
            while (pos-- > 0)
                rrb(b);
        }
		pa(a, b);
        list_len--;
    }
}

int	check_list_lenght(t_stack *a)
{
	int	size;

	if (ft_lstsize(a) <= 100)
		size = ft_lstsize(a) / 6;
	if (ft_lstsize(a) <= 500)
		size = ft_lstsize(a) / 12;
	else
		size = ft_lstsize(a) / 20;
	return (size);
}

void	push_to_b(t_stack **a, t_stack **b, int *arr)
{
	int(size), (i), (list_size);

	size = check_list_lenght(*a);
	i = 0;
	list_size = ft_lstsize(*a);
	int s = list_size;
	while (list_size != 0)
	{
		if ((*a)->nbr <= arr[i])
		{
			pb(a, b);
			rb(b);
			// if (i < size)
				i++;
			// if (size < s )
				size++;
			list_size--;
		}
		else if ((*a)->nbr <= arr[size])
		{
			pb(a, b);
			check_b(b);
			// if (i < size)
				i++;
			// if (size < s)
				size++;
			list_size--;
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
