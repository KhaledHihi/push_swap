/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:07:10 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/20 07:19:27 by khhihi           ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rra(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!(*list) || !list)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!(*list) || !list)
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
	write(1, "rrb\n", 4);
}

void	rr(t_stack **a_list, t_stack **b_list)
{
	ra(a_list);
	rb(b_list);
	write(1, "rr\n", 3);
}
