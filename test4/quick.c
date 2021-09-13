#include "push_swap.h"

int	is_over5_inA(t_list *list)
{
	if(searchA_last(list)->sorted == SORTED)
		return(OVER);
	if(searchA_last(list)->order - searchA_start(list)->order > 5)
		return(OVER);
	else
		return(UNDER);
}

void	quick(t_list *list)
{
	int	*instA;
	int	*instB;

	while(is_sorted(list) == NOSORTED)
	{
		while(is_over5_inA(list) == OVER)
			push2b_overcenter(list);
		//sort_both(list);
		//push2a(list);
	}
}