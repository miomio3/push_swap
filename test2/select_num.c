#include "push_swap.h"

out2	select_num(t_list *alast, t_list *blast, t_list *a0, t_list *b0)
{
	out2	out;
	int		rr;
	int		rrr;
	int		rrbra;
	int		rrarb;
	int		re;

	rr = search_Alast(alast)->order - alast->order + b0->order - search_Blast(alast)->order;
	rrr = a0->order + 1 + search_last(alast)->order - blast->order + 1;
	rrbra = search_Alast(alast)->order - alast->order + search_last(alast)->order - blast->order + 1;
	rrarb = a0->order + 1 + b0->order - search_Blast(alast)->order;
	re = select_smallerin4(rr, rrr, rrbra, rrarb);
	if(re == rr)
		assign_out2(&out, RR, alast, b0);
	else if(re == rrr)
		assign_out2(&out, RRR, a0, blast);
	else if(re == rrarb)
		assign_out2(&out, RRBRA, alast, blast);
	else
		assign_out2(&out, RRARB, a0, b0);
	return(out);
}

out2	select_num_instruction(t_list *list, int *array, int i, int argc)
{
	t_list	*alast;
	t_list	*blast;
	t_list	*a0;
	t_list	*b0;
	out2	out;

	alast = search_num_nosorted_fromlast(list, array[i],A);
	blast = search_num_nosorted_fromlast(list, array[argc - 2 - i], B);
	a0 = search_num_nosorted_from0(list, array[i],A);
	b0 = search_num_nosorted_from0(list, array[argc - 2 - i], B);
	out = select_num(alast, blast, a0, b0);
	return(out);
}
