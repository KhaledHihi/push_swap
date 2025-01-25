/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:01:54 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/25 08:31:19 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **list)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	tmp = first->nbr;
	first->nbr = second->nbr;
	second->nbr = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **list)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	tmp = first->nbr;
	first->nbr = second->nbr;
	second->nbr = tmp;
	write(1, "sb\n", 3);
}

void	pa(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pa\n", 3);
}

void	pb(t_stack **src, t_stack **dst)
{
	t_stack	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pb\n", 3);
}
