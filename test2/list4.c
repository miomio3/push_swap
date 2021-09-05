#include "push_swap.h"

t_list	*search_last(t_list *list)
{
	return(search_list(list, 0)->prev);
}