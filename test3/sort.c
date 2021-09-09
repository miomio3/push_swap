#include "push_swap.h"

static int	*make_int(t_list *list, int argc)
{
	int		i;
	int		*array;
	t_list	*p;

	array = malloc(sizeof(int) * argc - 1);
	p = list;
	i = 0;
	while(i < argc - 1)
	{
		array[i] = p->num;
		p->arrayorder = i;
		p = p->next;
		i++;
	}
	return(array);
}

void	ra_2push(t_list *list)
{
	int		Alast;
	t_list	*p;

	p = list;
	Alast = search_Alast(list)->order;
	if(p->order < Alast / 2)
	{
		while(p->order != Alast)
		{
			p = search_prev(p, A);
			rra(list, PUT);
		}
	}
	else
	{
		while(p->order != Alast)
		{
			p = search_next(p, A);
			ra(list, PUT);
		}
	}
}

void	push2b(t_list *list, int *array, int argc)
{
	t_list	*p;
	t_list	*back;
	int		i;

	i = 0;
	while(i < PUSH2B && is_sorted(list) == NOSORTED)
	{
		p = search_pushnum_from0(list, argc);
		back = search_pushnum_fromlast(list, argc);
		if(p->order + 1 > search_Alast(list)->order - back->order)
				p = back;
		ra_2push(p);
		if(is_sorted(list) == NOSORTED)
			pb(list);
		i++;
	}
}

void	sort(t_list *list, int argc)
{
	int	*array;
	int	i;

	array = make_int(list, argc);
	bouble(array, argc, list);
	i = 0;
	push2b(list, array, argc);
	sort2(list, array, argc);
	free(array);
}