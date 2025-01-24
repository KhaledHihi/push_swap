/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:36:10 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/23 09:52:58 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r(t_stack **list)
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

void	rr(t_stack **a, t_stack **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}

void	s(t_stack **list)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!list || !(*list))
		return ;
	first = *list;
	second = (*list)->next;
	tmp = first->nbr;
	first->nbr = second->nbr;
	second->nbr = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	s(a);
	s(b);
	write(1, "ss\n", 3);
}

void	rrrr(t_stack **list)
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
}
