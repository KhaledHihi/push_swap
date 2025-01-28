/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:02:56 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/28 13:46:45 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *str, t_stack **a, char **arr)
{
	long	r;

	int (i), (s);
	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i++] - 48);
		if ((r * s) > 2147483647 || (r * s) < -2147483648)
		{
			ft_error(a);
			return (ft_free_split(arr), write(2, "Error\n", 6), exit(1), 0);
		}
	}
	return (s * r);
}
