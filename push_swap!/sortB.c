#include "push_swap.h"

int	countB(t_list *list)
{
	int	last;
	int	first;

	first = searchB_first(list)->order;
	last = search_last(list)->order;
	return(last - first + 1);
}

int	*sortB(t_list *list)
{
	int	count;
	int	*re;

	count = countB(list);
	if(count == 2)
		re = sort2B(list);
	else if(count == 3)
		re = sort3B(list);
	else
	{
		re = malloc(sizeof(int));
		re[0] = END;
	}
	return(re);
}