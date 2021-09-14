#include "push_swap.h"

int	countA(t_list *list)
{
	t_list	*p;
	int		i;

	p = searchA_start(list);
	i = 0;
	while(p->enst != END)
	{
		p = search_next(p, A);
		i++;
	}
	return(i);
}

int	*sortA(t_list *list)
{
	int	count;
	int	*array;

	count = countA(list);
	if(count == 2)
		array = sort2A(list);
	return(array);
}