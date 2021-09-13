#include "push_swap.h"


t_list	*searchB_smallest_arrayorder(t_list *list)
{
	t_list	*p;
	t_list	*re;

	p = searchB_end(list);
	re = p;
	while(p->enst != START)
	{
		if(re->arrayorder > p->arrayorder)
			re = p;
		p = search_next(p, B);
	}
	return(re);
}

t_list	*searchB_biggest_arrayorder(t_list *list)
{
	t_list	*p;
	t_list	*re;

	p = searchB_end(list);
	re = p;
	while(p->enst != START)
	{
		if(re->arrayorder < p->arrayorder)
			re = p;
		p = search_next(p, B);
	}
	return(re);
}

int	centerB_arrayorder(t_list *list)
{
	t_list	*biggest;
	t_list	*smallest;
	int		center;

	biggest = searchB_biggest_arrayorder(list);
	smallest = searchB_smallest_arrayorder(list);
	center = (biggest->arrayorder - smallest->arrayorder) / 2;
	return(center);
}
