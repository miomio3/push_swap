#include "push_swap.h"


t_list *searchB_biggercenter(t_list *list, int center)
{
	t_list	*p;
	t_list	*first;
	int		i;

	p = searchB_first(list);
	first = p;
	i = 0;
	while((p != first || i++ == 0) && p->arrayorder >= center )
		p = search_next(p, B);
	return(p);
}


void	push2a_biggercenter(t_list *list)
{
	int		center;
	t_list	*p;

	center = centerB_arrayorder(list);
	p = searchB_biggercenter(list, center);
	while(p->arrayorder < center)
	{
		if(rb2top_times(p) < rrb2top_times(p))
			rb2top(p, PUT);
		else
			rrb2top(p, PUT);
		pa(list, PUT);
		p = searchB_biggercenter(list, center);
	}
}