#include "push_swap.h"

t_list	*search_pushnum_from0(t_list *list, int *array, int argc, int a_b)
{
	t_list	*p;
	int		i;
	int		f;

	if(a_b == A)
		p = search_list(list, 0);
	else
		p = search_Blast(list);
	f = 1;
	while(f)
	{
		i = 0;
		while(i < PUSH2B && f)
			if(p->num == array[argc - 2 - i++])
				f = 0;
		p = p->next;
	}
	return(p->prev);
}


t_list	*search_pushnum_fromlast(t_list *list, int *array, int argc, int a_b)
{
	t_list	*p;
	int		i;
	int		f;

	if(a_b == A)
		p = search_Alast(list);
	else
		p = search_list(list, argc - 2);
	f = 1;
	while(f)
	{
		i = 0;
		while(i < PUSH2B && f)
			if(p->num == array[argc - 2 - i++] && f)
				f = 0;
		p = p->prev;
	}
	return(p->next);
}

t_list	*search_listnum_nosorted(t_list *list, int num, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
	{
		p = search_Alast(list);
		while(p->num != num || p->sorted != 0)
			p = p->prev;
	}
	else
	{
		p = search_Blast(list);
		while(p->num != num || p->sorted != 0)
			p = p->next;
	}
	return(p);
}
