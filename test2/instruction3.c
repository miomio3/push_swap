#include "push_swap.h"

void	rrr2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	
}

void	instrution2top(int instration, t_list *pa, t_list *pb, int Alast, int Blast)
{
	if(instration == RRR)
	{
		while(pa->order != Alast && pa->order != Blast)
			rrr(pa);
		while(pa->order != Alast)
			rra(pa, PUT);
		while(pb->order != Blast)
			rrb(pb, PUT);
	}
	else if(instration == RR)
	{
		while(pa->order != Alast && pa->order != Blast)
			rr(pa);
		while(pa->order != Alast)
			ra(pa, PUT);
		while(pb->order != Blast)
			rb(pb, PUT);
	}
	if(instration == RRARB)
		rrarb2top(pa, pb, Alast, Blast);
	if(instration == RRBRA)
		rrbra2top(pa, pb, Alast, Blast);
}
