/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:13:29 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/13 21:18:50 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(long value)
{
    t_stack *node;

    node = (t_stack*)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->nbr = value;
    node->next = NULL;
    return (node);
}
