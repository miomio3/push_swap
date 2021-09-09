#include "push_swap.h"

int	select_instruction2sort(int Alast, int Blast, t_list *firstA, t_list *firstB)
{
	int	rr;
	int	rrr;
	int	rrbra;
	int	rrarb;
	int	re;

	rr = select_bigger(ra2top_times(firstA),  rb2top_times(firstB) - 1);
	rrr = select_bigger(rra2top_times(firstA) - 1, rrb2top_times(firstB));
	rrbra = ra2top_times(firstA) + rrb2top_times(firstB);
	rrarb = rra2top_times(firstA) - 1 + rb2top_times(firstB) - 1;
	re = select_smallerin4(rr, rrr, rrbra, rrarb);
	if(re == rr)
		return(RR);
	else if(re == rrr)
		return(RRR);
	else if(re == rrbra)
		return(RRBRA);
	else
		return(RRARB);
}

void	instruction2sort(t_list *pa, t_list *pb, t_list *firstA, t_list *firstB)
{
	int	re;

	re = select_instruction2sort(search_Alast(pa)->order, search_Blast(pb)->order, firstA, firstB);
	if(re == RR)
		rr2sort(firstA, firstB);
	else if(re == RRR)
		rrr2sort(firstA, firstB);
	else if(re == RRBRA)
		rrbra2sort(firstA, firstB);
	else
		rrarb2sort(firstA, firstB);
}

void	swap2sort(t_list *pa, t_list *pb, int i)
{
	t_list	*first_sortedA;
	t_list	*first_sortedB;

	if(i == 0)
	{
		pa->sorted = SORTED;
		pb->sorted = SORTED;
		return;
	}
	first_sortedA = search_last_biggestarray_sorted(pa, A);
	first_sortedB = search_last_biggestarray_sorted(pa, B);
	instruction2sort(pa, pb, first_sortedA, first_sortedB);
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}