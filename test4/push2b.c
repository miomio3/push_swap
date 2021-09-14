#include "push_swap.h"

t_list *searchA_undercenter(t_list *list, int center)
{
	t_list	*p;

	p = searchA_start(list);
	while(p->enst != END && p->arrayorder < center)
		p = search_next(p, A);
	return(p);
}

void	push2b_undercenter(t_list *list)
{
	t_list	*p;
	int		*array;
	int		first;
	int		center;

	center = centerA_arrayorder(list);
	p = searchA_undercenter(list, center);
	while(p->arrayorder >= center && is_sorted(list) == NOSORTED)
	{
		array = ra2top(p, PUT);
		if(is_sorted(list) == NOSORTED)
			pb(list, PUT);
		p = searchA_undercenter(list, center);
		free(array);
	}
}