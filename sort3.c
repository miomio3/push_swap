#include "push_swap.h"

t_list	*search_lowest_in3(t_list *list)
{
	t_list	*zero;
	t_list	*first;
	t_list	*second;
	size_t	i;

	i = 0;
	zero = list;
	first = list->next;
	second = list->next->next;
	if(zero->num > first->num)
		zero = first;
	if(zero->num > second->num)
		zero = second;
	return(zero);
}

void	sort_three(t_list *list, int argc)
{
	t_list	*zero;

	zero = search_lowest_in3(list);
	if(zero->order == 2 || zero->order == 1)
		op_rra(zero, argc - 1);
	swap_top2(zero, 2);
}

