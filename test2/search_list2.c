#include "push_swap.h"

t_list	*search_listnum(t_list *list, int num, int ab)
{
	t_list	*p;

	if(ab == A)
		p = search_Alast(list);
	else
		p = search_Blast(list);
	while(p->num != num && p->a_b == ab)
		p = p->prev;
	if(p->a_b != ab)
		return(NULL);
	return(p);
}

t_list	*search_pushnum_from0(t_list *list, int *array, int argc, int a_b, int times)
{
	t_list	*p;
	int		f;
	int		i;

	if(a_b == A)
		p = search_list(list, 0);
	else
		p = search_Blast(list);
	f = 1;
	while(f)
	{
		i = -1;
		while(++i < PUSH2B - times && f)
			if(p->num == array[argc - 2 - times - i] && f)
				f = 0;
		p = p->next;
	}
	return(p->prev);
}


t_list	*search_pushnum_fromlast(t_list *list, int *array, int argc, int a_b, int times)
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
		i = -1;
		while(++i < PUSH2B - times && f)
			if(p->num == array[argc - 2 - times - i] && f)
				f = 0;
		p = p->prev;
	}
	return(p->next);
}

t_list	*search_num_nosorted_fromlast(t_list *list, int *array, int arraysize, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
		p = search_Alast(list);
	else
		p = search_last(list);
	while((is_array(p , array, arraysize) == NOEXIST || p->sorted == SORTED) && p->order != 0)
		p = p->prev;
	return(p);
}

t_list	*search_num_nosorted_from0(t_list *list, int *array, int arraysize, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
		p = search_list(list, 0);
	else
		p = search_Blast(list);
	while((is_array(p , array, arraysize) == NOEXIST || p->sorted != 0) && p->last != 1)
		p = p->next;
	return(p);
}

