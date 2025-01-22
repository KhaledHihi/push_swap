/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 05:05:04 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/21 15:57:19 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_b(t_stack **b)
{
	if (*b && (*b)->next && (*b)->nbr < (*b)->next->nbr)
		sb(b);
}

int	max_index(t_stack **b)
{
	t_stack	*move;
	int		max;
	int		max_pos;
	int		current_pos;

	move = *b;
	max = move->nbr;
	max_pos = 0;
	current_pos = 0;
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
	return (max_pos);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;

	i = 0;
	while (size - 1 > i)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*list_to_arr(t_stack *lst)
{
	int	i;
	int	len;
	int	*arr;

	i = 0;
	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i] = lst->nbr;
		lst = lst->next;
		i++;
	}
	sort_int_tab(arr, len);
	return (arr);
}
