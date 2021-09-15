#include "push_swap.h"

void	reset_enst(t_list *list)
{
	t_list	*p;
	t_list	*next;

	p = searchA_last(list);
	next = search_next(p, A);
	if(isA_sorted(list) == SORTED)
		return;
	if(p->sorted == SORTED && search_next(p, A)->sorted == NOSORTED)
		rra(list, PUT);
	while(next->sorted != SORTED && next->enst != START)
	{
		if(p->enst != START)
			p->enst = NOTHING;
		rra(list, PUT);
		p = searchA_last(list);
		next = search_next(p, A);
	}
/* 	if(p->enst != START)
		p->enst = END; */
}

void	quick(t_list *list)
{
	int	*instA;

	if(isA_over3(list) == UNDER)
		put_inst(sortA_first(list), NULL);
	else
	{
		while(is_sorted(list) == NOSORTED)
		{
			push2b_undercenter(list);//numが半分＜以下のもの＞をbへ
			//reset_enst(list);
			while(isB_over3(list) == OVER && is_sorted(list) == NOSORTED)
				push2a_biggercenter(list);//numが半分＜より大きいもの＞をaへ。enstを最初と最後につけるのを忘れずに。
			sort_both(list);
			push2a_ra(list);//raは全てpush2aしてから行う。//sortedにして、enstを初期化するのを忘れずに。
		}
	}
}