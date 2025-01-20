/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:39:33 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/20 04:48:10 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *list, int len)
{
	if (!list || !list->next)
		return 0;

	int i = 0;
	while(list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}
void	checker();

int main(int ac, char *av[])
{
	t_stack	*list;

	list = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (1);
	arguments(ac, av, &list);
}
