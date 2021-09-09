#include "push_swap.h"
/* 
t_list	*search_smallestarray_both(t_list *list, int a_b)
{

	t_list	*re;
	t_list	*p;
	t_list	*first;
	int		i;

	p = search_sorted(list, a_b);
	re = p;
	first = p;
	i = 0;
	while(p != first || i++ == 0)
	{
		if(re->arrayorder > p->arrayorder)
			re = p;
		p = search_next(p, a_b);
	}
	return(re);
} */

t_list	*search_lastAB(t_list *p, int a_b)
{
	if(a_b == A)
		return(search_Alast(p));
	else
		return(search_last(p));
}

t_list	*search_biggest(t_list *p, int a_b)
{
	t_list	*ptr;
	t_list	*first;
	t_list	*re;
	int		i;

	if(a_b == A)
		first = search_Alast(p);
	else
		first = search_Blast(p);
	ptr = first;
	re = first;
	i = 0;
	while(ptr != first || i++ == 0)
	{
		if(ptr->num <= search_next(ptr, a_b)->num)
			re = search_next(ptr, a_b);
		ptr = search_next(ptr, a_b);
	}
	return(re);
}

t_list	*search_smallestlast(t_list *p, int a_b)
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
		if(re->num >= search_next(ptr, a_b)->num)
			re = search_next(ptr, a_b);
		ptr = search_next(ptr, a_b);
	}
	if(re == first)
		return(search_lastAB(p, a_b));
	return(re);
}

t_list	*search_last_biggestarray_sorted(t_list *list, int a_b)
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
