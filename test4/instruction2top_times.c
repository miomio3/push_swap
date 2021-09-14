#include "push_swap.h"

int	ra2top_times(t_list *pa)
{
	return(searchA_last(pa)->order - pa->order);
}

int	rra2top_times(t_list *pa)
{
	return(pa->order + 1);
}

int	rb2top_times(t_list *pb)
{
	return(pb->order - searchB_first(pb)->order);
}

int	rrb2top_times(t_list *pb)
{
	return(search_last(pb)->order - pb->order + 1);
}