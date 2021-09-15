#include "push_swap.h"

int	isA_over3(t_list *list)
{
	t_list	*last;

	last = searchA_last(list);
	if(last->order < 3)
		return(UNDER);
	else
		return(OVER);
}

int	isB_over3(t_list *list)
{
	t_list	*first;
	t_list	*last;

	last = search_last(list);
	first = searchB_first(list);
	if(last->order - first->order < 3)
		return(UNDER);
	else
		return(OVER);
}

int	isA_sorted_enst(t_list *list)
{
	t_list	*p;
	t_list	*next;

	p = searchA_start(list);
	while(p->enst != END)
	{
		next = search_next(p, A);
		if(p->arrayorder > next->arrayorder)
			return(NOSORTED);
	}
	return(SORTED);
}

int	is_sorted(t_list *list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->num >= p->next->num && p->last == 0)
		p = p->next;
	if(p->last == 1)
		return(SORTED);
	else
		return(NOSORTED);
}

int	is_B(t_list *list)
{
	t_list	*p;

	p = list;
	while(p->a_b == A && p->last == 0)
		p = p->next;
	if(p->a_b == B)
		return(EXIST);
	else
		return(NOEXIST);
}
