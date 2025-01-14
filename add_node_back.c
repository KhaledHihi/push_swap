/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:12:41 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/03 10:13:28 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_node_back(t_stack **node, t_stack *new)
{
    t_stack *new_node;
    if (!node || !new)
        return ;
    if (!(*node))
    {
        *node = new;
        return ;
    }
    new_node = *node;
    while(new_node->next)
   {
        new_node = new_node->next;
   }
   new_node->next = new;
}
