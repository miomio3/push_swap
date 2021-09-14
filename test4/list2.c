#include "push_swap.h"

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

/* 
int	is_sortedAB(t_list *p, int a_b)
{
	t_list	*first;
	t_list	*ptr;
	int		i;

	first = search_smallestlast(p, a_b);
	ptr = first;
	while(ptr->num <= search_prev(ptr, a_b)->num && search_prev(ptr, a_b) != first)
		ptr = search_prev(ptr, a_b);
	if(search_prev(ptr, a_b) == first)
		return(SORTED);
	return(NOSORTED);
}
 */