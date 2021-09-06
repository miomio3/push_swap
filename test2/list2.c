#include "push_swap.h"

void	free_list(t_list *list)
{
	t_list	*p;

	p = list;
	while(p)
	{
		free(p);
		list = NULL;
	}
}

int	is_B(t_list *list)
{
	t_list	*p;

	p = list;
	while(p->a_b == A && p->last == 0)
		p = p->next;
	if(p->a_b == B)
		return(1);
	else
		return(-1);
}
