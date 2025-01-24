/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 05:11:35 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/24 16:56:13 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;

}					t_stack;

char	*get_next_line(int fd);
int		ft_duplicate(t_stack *lst);
int		ft_check(char *str);
void	ft_error(t_stack **stack);
void	ft_free_split(char **split);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
t_stack	*create_node(long value);

void	add_node_back(t_stack **node, t_stack *new1);
int		ft_lstsize(t_stack *lst);
void	print_node(t_stack *lst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **list);
void	rb(t_stack **list);
void	sa(t_stack **list);
void	sb(t_stack **list);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a_list, t_stack **b_list);
void	rra(t_stack **list);
void	rrb(t_stack **list);
void	rrr(t_stack **a, t_stack **b);
void	rrrr(t_stack **list);

#endif
