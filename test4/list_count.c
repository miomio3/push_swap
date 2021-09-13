#include "push_swap.h"

int	countA(t_list *list)
{
	t_list	*p;
	t_list	*first;
	int		i;

	p = search_list(list, 0);
	first = p;
	i = 0;
	while(p->a_b == A && (i == 0 || p != first))
	{
		p = p->next;
		i++;
	}
	return(i);
}
