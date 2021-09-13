#include "push_swap.h"

int	*create_array2push2b(int inst, int times)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * times + 2);
	i = times;
	array[times + 1] = END;
	array[times] = PB;
		while(i--)
			array[i] = RA;
}

t_list	*search_pushnum_from0(t_list *list, int argc, int times)
{
	t_list	*p;
	t_list	*first;
	int		i;

	p = search_nosorted_fromfirst(list, A);
	p = first;
	i = 0;
	while(p->arrayorder <= argc - 2 - argc / (2 * times) && (p != first || i++ == 0))
		p = search_next(p, A);
	if(p->arrayorder <= argc - 2 - argc / (2 * times) || p->sorted == SORTED)
		return(NULL);
	return(p);
}

t_list	*search_pushnum_fromlast(t_list *list, int argc, int times)
{
	t_list	*p;
	t_list	*first;
	int		i;

	p = search_nosorted_fromlast(list, A);
	first = p;
	i = 0;
	while(p->arrayorder <= argc - 2 - argc / (2 * times) && (p != first || i++ == 0))
		p = search_prev(p, A);
	if(p->arrayorder <= argc - 2 - argc / (2 * times) || p->sorted == SORTED)
		return(NULL);
	return(p);
}

int	*inst_push2b(t_list *list, int argc, int times)
{
	int		*array;
	t_list	*first;
	t_list	*last;
	int		i;
	int		last_distance;

	first = search_pushnum_from0(list, argc, times);
	last = search_pushnum_fromlast(list, argc, times);
	if(first == NULL && last == NULL)
		return(NULL);
	last_distance = smallest_distance2topB(last);
	if(last_distance < first->order)
	{
		array = create_array2push2b(RRA, last_distance);
		rra2top(last);
	}
	else
	{
		array = create_array2push2b(RA, first->order);
		ra2top(first);
	}
	return(array);
}
