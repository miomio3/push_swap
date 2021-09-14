#include "push_swap.h"

void	quick(t_list *list)
{
	int	*instA;
	int	*instB;

	if(isA_over3(list) == UNDER)
		//sortA(list);
	while(is_sorted(list) == NOSORTED)
	{
		push2b_undercenter(list);//途中。numが半分＜以下のもの＞をbへ
		while(searchA_last(list)->enst != END)
			ra(list, PUT);
		while(isB_over3(list) == OVER)
			push2a_biggercenter(list);//途中。numが半分＜より大きいもの＞をaへ。enstを最初と最後につけるのを忘れずに。
		sort_both(list);
		//push2a_ra(list);//raは全てpush2aしてから行う
		//ra2bottom(list);
	}
}