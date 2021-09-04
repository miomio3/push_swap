#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->num >= p->next->num && p->last == 0)
		p = p->next;
	if(p->last == 1)
		return(1);
	else
		return(-1);
}

int	next_instraction_inA(t_list *list, int array)
{
	int		f;
	t_list	*p;
	int		last;

	p = search_listnum(list, array, A);
	if(p == NULL)
		return(NOINSTRUCTION);
	last = search_Alast(list)->order;
	if(p->order == last)
		return(SA);
	if(p->order > last / 2)
		return(RA);
	else
		return(RRA);
}

void	sort2(t_list *list, int *array)
{
	t_list	*alist;
	t_list	*blist;

	alist = search_Alast(list);
	blist = search_Blast(list);
}