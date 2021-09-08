#include "push_swap.h"

out2	select_instruction(t_list *pa, t_list *pb)
{
	out2	out;
	int		rr;
	int		rrr;
	int		rrbra;
	int		rrarb;
	int		re;

	rr = select_bigger(search_Alast(pa) - pa->order ,pb->order - search_Blast(pa)->order);
	rrr = select_bigger(pa->order + 1 , search_last(pa)->order - pb->order + 1);
	rrbra = search_last(pa)->order - pb->order + 1 + search_Alast(pa) - pa->order;
	rrarb =  pa->order + 1 + pb->order - search_Blast(pa)->order;
	re = select_smallerin4(rr, rrr, rrbra, rrarb);
	if(re == rr)
		assign_out2(&out, RR, pa, pb);
	else if(re == rrr)
		assign_out2(&out, RRR, pa, pb);
	else if(re == rrarb)
		assign_out2(&out, RRBRA, pa, pb);
	else
		assign_out2(&out, RRARB, pa, pb);
	return(out);
}

out2	select_num_instruction(t_list *list, int *array, int i, int argc)
{
	t_list	*pa;
	t_list	*pb;
	out2	out;

	pa = search_smallestarray_nosorted(list, A);
	pb = search_smallestarray_nosorted(list, B);
	out = select_instruction(pa, pb);
	return(out);
}
