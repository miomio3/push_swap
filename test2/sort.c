#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->num >= p->next->num && p->last == 0)
		p = p->next;
	if(p->last == 1)
		return(1);
	else
		return(-1);
}

int	next_instration2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	re;
	int	rr;
	int rrr;
	int rrarb;
	int rrbra;

	rr = select_bigger(Alast - pa->order, pb->order - Blast);
	rrr = select_bigger(pa->order + 1, search_last(pb)->order - pb->order + 1);
	rrarb = pa->order + 1 + pb->order - Blast;
	rrbra = search_last(pb)->order - pb->order + 1 + Alast - pa->order;
	re = rr;
	if(re > rrr)
		re = rrr;
	if(re > rrbra)
		re = rrbra;
	if(re > rrarb)
		return(RRARB);
	else if(re == rr)
		return(RR);
	else if(re == rrbra)
		return(RRBRA);
	else
		return(RRR);
}

void	push2top(t_list *list, int *array, int argc, int i)
{
	t_list	*pa;
	t_list	*pb;

	pa = search_listnum_nosorted(list, array[i]);
	pb = search_listnum_nosorted(list, array[PUSH2B - 1 - i]);
	instration2top(next_instration2top(pa, pb, search_Alast(list)->order, search_Blast(list)->order), pa, pb, search_Alast(list)->order, search_Blast(list)->order);
}

void	sort2(t_list *list, int *array, int argc)
{
	int	i;

	i = 0;
	while(i < PUSH2B)
	{
		push2top(list, array, argc, i);
		//swap2sort
		i++;
	}
}