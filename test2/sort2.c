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

	out = select_num_instruction(list, array, i, argc);
	if (i != 0)
		out = instrution2top(out.instruction, out.pa, out.pb, search_Alast(list)->order, search_Blast(list)->order);
	return(out);
}

void	sort2(t_list *list, int *array, int argc)
{
	int		i;
	out2	out;

	i = 0;
	while(i <= PUSH2B && is_sortedAB(list, A) == NOSORTED && is_sortedAB(list, B) == NOSORTED)
	{
		out = push2top(list, array, argc, i);
		delarray_from0(array, argc - 1 - i * 2, out.pa->num);
		delarray_fromlast(array, argc - 2 - i * 2, out.pb->num);
		swap2sort(out.pa, out.pb, i);
		i++;
	}
	/* while(is_sortedAB(list, A) == NOSORTED)
		sortB(list);
	while(is_sortedAB(list, B) == NOSORTED)
		sortA(list);
	while(is_sorted(list) == NOSORTED)
		last2top(list)//最終段階 */
}