#include "push_swap.h"

void	sort_both(t_list *list)
{
	int	*instA;
	int	*instB;

	instA = sortA(list);
	//instB = sortB(list);
	put_inst(instA, instB);
}