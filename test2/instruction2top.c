#include "push_swap.h"

void	rrr2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	i;
	int	smaller;
	int bigger;

	smaller = select_smaller(pa->order + 1, search_last(pb)->order - pb->order + 1);
	bigger = select_bigger(pa->order + 1, search_last(pb)->order - pb->order + 1);
	i = 0;
	while(i++ < smaller)
		rrr(pa);
	i = 0;
	if(pa->order + 1 > Blast - pb->order + 1)
		while(i++ < bigger - smaller)
			rra(pa, PUT);
	else
		while(i++ < bigger - smaller)
			rrb(pb, PUT);
}

void	rr2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
		int	i;
	int	smaller;
	int bigger;

	smaller = select_smaller(Alast - pa->order, pb->order - Blast);
	bigger = select_bigger(Alast - pa->order, pb->order - Blast);
	i = 0;
	while(i++ < smaller)
		rr(pa);
	i = 0;
	if(Alast - pa->order + 1 > pb->order - Blast + 1)
		while(i++ < bigger - smaller)
			ra(pa, PUT);
	else
		while(i++ < bigger - smaller)
			rb(pb, PUT);
}

out2	instrution2top(int instration, t_list *pa, t_list *pb, int Alast, int Blast)
{
	out2	out;

	if(instration == RRR)
		rrr2top(pa, pb, Alast, Blast);
	else if(instration == RR)
		rr2top(pa, pb, Alast, Blast);
	else if(instration == RRARB)
		rrarb2top(pa, pb, Alast, Blast);
	else if(instration == RRBRA)
		rrbra2top(pa, pb, Alast, Blast);
	out.pa = search_Alast(pa);
	out.pb = search_Blast(pa);
	return(out);
}
