#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;

}					t_stack;

void				sort_two(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
int					ft_duplicate(t_stack	*lst);
int					ft_check(char *str);
void				ft_error(t_stack **stack);
void				ft_free_split(char **split);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
t_stack				*create_node(long value);
void				add_node_back(t_stack **node, t_stack *new);
int					ft_lstsize(t_stack *lst);
void				print_node(t_stack *lst);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ra(t_stack **list);
void				rb(t_stack **list);
void				sa(t_stack **list);
void				sb(t_stack **list);
void 				rr(t_stack **a_list ,t_stack **b_list );
void				rra(t_stack **list);
void				rrb(t_stack **list);

#endif
