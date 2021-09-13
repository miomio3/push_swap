#include "push_swap.h"

void	quick(t_list *list)
{
	int	*instA;
	int	*instB;

	while(is_sorted(list) == NOSORTED)
	{
		instA = inst_push2b(list);
		if(is_B == EXIST)
			instB = inst_quick2a(list);
		do_inst(instA, instB);
	}
}