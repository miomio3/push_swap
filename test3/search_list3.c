#include "push_swap.h"

/* t_list	*search_smallest0(t_list *p, int a_b)
{
	t_list	*ptr;
	t_list	*first;
	t_list	*re;
	int		i;

	if(a_b == A)
		first = search_biggest(p, a_b);
	else
		first = search_biggest(p, a_b);
	ptr = first;
	re = first;
	i = 0;
	while(ptr != first || i++ == 0)
	{
		if(re->num < search_next(ptr, a_b)->num)
			re = search_next(ptr, a_b);
		ptr = search_next(ptr, a_b);
	}
	return(re);
}
 */


t_list	*search_sorted(t_list *list, int a_b)
{
	t_list	*p;
	t_list	*first;
	int		i;

	if(a_b == A)
		p = search_Alast(list);
	else
		p = search_Blast(list);
	first = p;
	i = 0;
	while(p != first || i++ == 0)
	{
		if(p->sorted == SORTED)
			break;
		p = search_next(p, a_b);
	}
	return(p);
}

t_list	*search_nosorted(t_list *list, int a_b)
{
	t_list	*p;
	t_list	*first;
	int		i;

	if(a_b == A)
		p = search_Alast(list);
	else
		p = search_Blast(list);
	first = p;
	i = 0;
	while(p != first || i++ == 0)
	{
		if(p->sorted == NOSORTED)
			break;
		p = search_next(p, a_b);
	}
	return(p);
		
}

t_list	*search_smallestarray_nosorted(t_list *list, int a_b)
{
	t_list	*re;
	t_list	*p;
	t_list	*first;
	int		i;

	p = search_nosorted(list, a_b);
	re = p;
	first = p;
	i = 0;
	while(p != first || i++ == 0)
	{
		if(re->arrayorder > p->arrayorder && p->sorted == NOSORTED)
			re = p;
		p = search_next(p, a_b);
	}
	return(re);
}

t_list	*search_smallestarray_sorted(t_list *list, int a_b)
{
	t_list	*first;
	t_list	*p;
	t_list	*re;
	int		i;

	p = search_sorted(list, a_b);
	re = p;
	first = p;
	i = 0;
	while(p != first || i++ == 0)
	{
		if(re->arrayorder > p->arrayorder && p->sorted == SORTED)
			re = p;
		p = search_next(p, a_b);
	}
	return(re);
}

t_list	*search_arrayorder(t_list *list, int i)
{
	while(list->arrayorder != i)
		list = list->next;
	return(list);
}
