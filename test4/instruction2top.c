#include "push_swap.h"

void	ra2top(t_list *list)
{
	int	i;

	i = search_Alast(list)->order - list->order;
	while(i--)
		ra(list, NOPUT);
}

void	rra2top(t_list *list)
{
	int	i;

	i = list->order;
	while(i--)
		rra(list, NOPUT);
}