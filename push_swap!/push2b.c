#include "push_swap.h"

int	count_array(int *array)
{
	int	i;

	i = 0;
	while(array[i] != END)
		i++;
	return(i);
}

t_list *searchA_undercenter(t_list *list, int center)
{
	t_list	*p;
	t_list	*prev;

	p = searchA_last(list);
	prev = search_prev(p, A);
	while(p->arrayorder < center && prev->sorted != SORTED && p->enst != START)
	{
		p = prev;
		prev = search_prev(p, A);
	}
	return(p);
}

void	push2b_undercenter(t_list *list, int times)
{
	t_list	*p;
	int		*array;
	int		center;
	int		is;
	int		i;

	center = centerA_arrayorder(list);
	p = searchA_undercenter(list, center);
	is = is_sorted(list);
	i = 0;
	while(p->arrayorder >= center && p->sorted == NOSORTED && is == NOSORTED)
	{
		array = ra2top(p, PUT);
		if(is_sorted(list) == NOSORTED)
			pb(list, PUT);
		p = searchA_undercenter(list, center);
		i = i + count_array(array);
		free(array);
		is = is_sorted(list);
	}
	if(isA_sorted(list) == NOSORTED && times != 0)
		while(i--)
			rra(list, PUT);
}