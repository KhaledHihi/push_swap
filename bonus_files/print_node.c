/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:30:58 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/28 13:34:34 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_node(t_stack *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}
