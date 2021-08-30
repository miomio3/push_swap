#include "push_swap.h"

t_list	*search_zero(t_list *list)
{
	t_list	*zero;
	size_t	i;

	i = 0;
	zero = list;
	while(i++ < 2)
		if(zero->num > zero->next->num)
			zero = zero->next;
	return(zero);
}

void	sort3(t_list *list)
{
	t_list	*zero;

	zero = search_zero(list);
}

