#include "push_swap.h"

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
			while(searchA_last(list)->enst != END && is_sorted(list) == NOSORTED)
				rra(list, PUT);
			while(isB_over3(list) == OVER && is_sorted(list) == NOSORTED)
				push2a_biggercenter(list);//numが半分＜より大きいもの＞をaへ。enstを最初と最後につけるのを忘れずに。
			sort_both(list);
			push2a_ra(list);//raは全てpush2aしてから行う。
		}
	}
}