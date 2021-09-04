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
			if(p->order == 0)
				p = search_Alast(list);
			else
				p = p->prev;
			rra(list);
		}
	}
	else
	{
		while(p->order != Alast)
		{
			p = p->next;
			ra(list);
		}
	}
}

void	push2b(t_list *list, int *array, int argc)
{
	t_list	*p;
	t_list	*back;
	int		i;

	i = 0;
	while(i < PUSH2B && is_sorted(list) == -1)
	{
		p = search_pushnum_from0(list, array, argc, A);
		back = search_pushnum_fromlast(list, array, argc, A);
		if(p->order + 1 > search_Alast(list)->order - back->order)
			p = back;
		ra_2push(p);
		if(is_sorted(list) == -1)
			pb(list);
		i++;
	}
}

void	insertion(t_list *list, int argc)
{
	int	*array;
	int	i;

	array = make_int(list, argc);
	bouble(array, argc);
	i = 0;
	push2b(list, array, argc);
	//sort2(list, array);
	while(is_B(list) == 1)
		pa(list);
}