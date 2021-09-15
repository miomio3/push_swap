#include "push_swap.h"

void	reset_enst(t_list *list)
{
	t_list	*p;
	int		i;

	p = searchA_last(list);
	i = 0;
	while(p->order != 0)
	{
		if(i == 0)
			p->enst = END;
		else
			p->enst = NOTHING;
		p = search_prev(p, A);
	}
	p->enst = START;
}

void	quick(t_list *list)
{
	int	*instA;
	int	i;

	if(isA_over3(list) == UNDER)
		put_inst(sortA_first(list), NULL);
	else
	{
		i = 0;
		while(is_sorted(list) == NOSORTED)
		{
			push2b_undercenter(list, i);//numが半分＜以下のもの＞をbへ
			if(i == 0)
				reset_enst(list);
			while(isB_over3(list) == OVER && is_sorted(list) == NOSORTED)
				push2a_biggercenter(list);//numが半分＜より大きいもの＞をaへ。enstを最初と最後につけるのを忘れずに。
			sort_both(list);
			push2a_ra(list);//raは全てpush2aしてから行う。//sortedにして、enstを初期化するのを忘れずに。
			i++;
		}
	}
}