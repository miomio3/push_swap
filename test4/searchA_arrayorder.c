#include "push_swap.h"

t_list	*searchA_smallest_arrayorder(t_list *list)
{
	t_list	*p;
	t_list	*re;

	p = searchA_end(list);
	re = p;
	while(p->enst != START)
	{
		p = search_prev(p, A);
		if(re->arrayorder > p->arrayorder)
			re = p;
	}
	return(re);
}

t_list	*searchA_biggest_arrayorder(t_list *list)
{
	t_list	*p;
	t_list	*re;

	p = searchA_end(list);
	re = p;
	while(p->enst != START)
	{
		p = search_prev(p, A);
		if(re->arrayorder < p->arrayorder)
			re = p;
	}
	return(re);
}

int	centerA_arrayorder(t_list *list)
{
	t_list	*biggest;
	t_list	*smallest;
	int		center;
	t_list	*re;

	biggest = searchA_biggest_arrayorder(list);
	smallest = searchA_smallest_arrayorder(list);
	center = (biggest->arrayorder + smallest->arrayorder + 1) / 2;
	return(center);
}
