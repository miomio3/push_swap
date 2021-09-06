#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->num >= p->next->num && p->last == 0)
		p = p->next;
	if(p->last == 1)
		return(SORTED);
	else
		return(NOSORTED);
}

out2	push2top(t_list *list, int *array, int argc, int i)
{
	t_list	*pa;
	t_list	*pb;
	out2	out;

	pa = search_listnum_nosorted(list, array[i], A);
	pb = search_listnum_nosorted(list, array[PUSH2B - 1 + i], B);
	out.pa = pa;
	out.pb = pb;
	if (i != 0)
		out= instrution2top(next_instration2top(pa, pb, search_Alast(list)->order, search_Blast(list)->order), pa, pb, search_Alast(list)->order, search_Blast(list)->order);
	return(out);
}

void	sort2(t_list *list, int *array, int argc)
{
	int		i;
	out2	out;

	i = 0;
	while(i <= PUSH2B && is_sorted(list) == NOSORTED)
	{
		out = push2top(list, array, argc, i);
		swap2sort(out.pa, out.pb, i);
		i++;
	}
}