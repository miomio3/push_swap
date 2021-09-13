#include "push_swap.h"

t_list *search_half(t_list *list)
{
	t_list	*p;
	int		center;

	center = centerA_arrayorder(list);
	p = searchA_start(list);
	while(p->enst != END && p->arrayorder < center)
		p = search_next(p, A);
	return(p);
}

int	count_push2b(t_list *list)
{
	int	i;
	int	Alast;
	int	Astart;
	int	center;

	Alast = searchA_last(list)->order;
	Astart = searchA_start(list)->order;
	center = centerA_arrayorder(list);
	i = Alast - Astart - center + 1;//Aの最後がendであることを前提としている
	return(i);
}

void	push2b_overcenter(t_list *list)
{
	t_list	*uc_s;
	int		s_order;
	int		*array;
	int		i;
	int		first;

	i = count_push2b(list);
	first = i;
	while(i-- && is_sorted(list) == NOSORTED)
	{
		uc_s = search_half(list);//startから探索
		if(ra2top_times(uc_s) < rra2top_times(uc_s))
			array = ra2top(uc_s, NOPUT);
		else
			array = rra2top(uc_s, NOPUT);
		put_inst(array, NULL);
		if(is_sorted(list) == NOSORTED)
			pb(list);
		if(i == first)
			searchB_first(list)->enst = START;
		else if(i == 0)
			searchB_first(list)->enst = END;
		free(array);
	}
}