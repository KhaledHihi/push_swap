/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:03:24 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/28 13:26:05 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *list)
{
	if (!list || !list->next)
		return (0);
	while (list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_duplicate(t_stack *lst)
{
	t_stack	*move;
	t_stack	*move_next;

	if (!lst)
		return (0);
	move = lst;
	while (move)
	{
		move_next = move->next;
		while (move_next)
		{
			if (move->nbr == move_next->nbr)
				return (write(2, "Error\n", 6), 0);
			move_next = move_next->next;
		}
		move = move->next;
	}
	return (1);
}
