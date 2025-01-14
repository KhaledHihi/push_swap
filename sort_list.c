#include "push_swap.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (size - 1 > i)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
int	*list_to_arr(t_stack *lst)
{
	int	i;
	int	len;
	int	*arr;

	i = 0;
	len = ft_lstsize(lst);
	arr = malloc(sizeof(int) * len);
	while (lst)
	{
		arr[i] = lst->nbr;
		lst = lst->next;
	}
	sort_int_tab(arr, len);
	return (arr);
}
