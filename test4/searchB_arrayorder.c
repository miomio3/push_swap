#include "push_swap.h"


t_list	*searchB_smallest_arrayorder(t_list *list)
{
	t_list	*p;
	t_list	*re;
	t_list	*first;
	int		i;

	p = searchB_first(list);
	first = p;
	re = p;
	i = 0;
	while(p != first || i++ == 0)
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
	t_list	*first;
	int		i;

	p = searchB_first(list);
	re = p;
	first = p;
	i = 0;
	while(p != first || i++ == 0)
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
	center = (biggest->arrayorder - smallest->arrayorder + 1) / 2;
	return(center);
}
