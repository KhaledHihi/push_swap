/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:12:41 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/28 13:33:50 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_node_back(t_stack **node, t_stack *new1)
{
	t_stack	*new_node;

	if (!node || !new1)
		return ;
	if (!(*node))
	{
		*node = new1;
		return ;
	}
	new_node = *node;
	while (new_node->next)
	{
		new_node = new_node->next;
	}
	new_node->next = new1;
}
