#include "push_swap.h"

void	rrarb2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	i;

	i = pa->order + 1;
	while(i--)
		rra(pa, PUT);
	i = pb->order - Blast;
	while(i--)
		rb(pb, PUT);
}

void	rrbra2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	i;

	i = Alast - pa->order;
	while(i--)
		ra(pa, PUT);
	i = search_last(pb)->order - pb->order + 1;
	while(i--)
		rrb(pb, PUT);
}