#include "push_swap.h"

void	ra2start(t_list *list)
{
	t_list	*last;

	last = searchA_last(list);
	while(last->enst != START && last->sorted != SORTED)
	{
		searchA_last(list)->sorted = SORTED;
		ra(list, PUT);
	}
	searchA_last(list)->sorted = SORTED;
	ra(list, PUT);
}

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
	int		i;
	t_list	*last;

	center = centerB_arrayorder(list);
	p = searchB_biggercenter(list, center);
	i = 0;
	while(p->arrayorder < center)
	{
		if(rb2top_times(p) < rrb2top_times(p))
			rb2top(p, PUT);
		else
			rrb2top(p, PUT);
		pa(list, PUT);
		if(i++ == 0)
			searchA_last(list)->enst = START;
		p = searchB_biggercenter(list, center);
	}
	last = searchA_last(list);
	if(last->enst != START)
		last->enst = END;
}

void	push2a_ra(t_list *list)
{
	int		i;
	t_list	*last;

	i = 0;
	while(is_B(list) == EXIST)
	{
		pa(list, PUT);
		if(i == 0)
			searchA_last(list)->enst = START;
		i++;
	}
	last = searchA_last(list);
	if(last->enst != START)
		last->enst = END;
	if(is_sorted(list) == NOSORTED)
	{
		ra2start(list);
		if(isA_over2(list) == UNDER)
			ra2start(list);
	}
}