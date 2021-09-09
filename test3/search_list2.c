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

t_list	*search_pushnum_from0(t_list *list, int argc)
{
	t_list	*p;
	int		f;
	int		i;

	p = search_list(list, 0);
	while(p->arrayorder <= argc - 2 - PUSH2B)
		p = search_next(p, A);
	return(p);
}


t_list	*search_pushnum_fromlast(t_list *list, int argc)
{
	t_list	*p;
	int		i;

	p = search_Alast(list);
	while(p->arrayorder <= argc - 2 - PUSH2B)
		p = search_prev(p, A);
	return(p);
}

t_list	*search_num_nosorted_fromlast(t_list *list, int num, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
	{
		p = search_Alast(list);
		while(p->num != num || p->sorted == SORTED)
			p = search_prev(p, a_b);
	}
	else
	{
		p = search_Blast(list);
		while(p->num != num || p->sorted == SORTED)
			p = search_next(p, a_b);
	}
	return(p);
}

t_list	*search_num_nosorted_from0(t_list *list, int num, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
	{
		p = search_list(list, 0);
		while(p->num != num || p->sorted == SORTED)
			p = p->next;
	}
	else
	{
		p = search_last(list);
		while(p->num != num || p->sorted == SORTED)
			p = p->prev;
	}
	return(p);
}

