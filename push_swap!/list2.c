#include "push_swap.h"

int	enstAlen(t_list *list)
{
	t_list	*start;
	t_list	*end;
	t_list	*Alast;

	start = searchA_start(list);
	end = searchA_end(list);
	Alast = searchA_last(list);
	if(start->order < end->order)
		return(end->order - start->order);
	else
		return(end->order + Alast->order - start->order + 1);
}