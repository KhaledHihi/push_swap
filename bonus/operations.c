/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:07:10 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/24 23:59:50 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!list || !(*list) || !((*list)->next))
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	move = *list;
	while (move->next)
		move = move->next;
	move->next = tmp;
}

void	rb(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!list || !(*list) || !((*list)->next))
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	move = *list;
	while (move->next)
		move = move->next;
	move->next = tmp;
}

void	rra(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!list || !(*list) || !(*list)->next)
		return ;
	move = *list;
	while (move->next)
	{
		tmp = move;
		move = move->next;
	}
	tmp->next = NULL;
	move->next = *list;
	*list = move;
}

void	rrb(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!list || !(*list) || !(*list)->next)
		return ;
	move = *list;
	while (move->next)
	{
		tmp = move;
		move = move->next;
	}
	tmp->next = NULL;
	move->next = *list;
	*list = move;
}

void	rrr(t_stack **a, t_stack **b)
{
	rrrr(a);
	rrrr(b);
}
