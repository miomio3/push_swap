#include "push_swap.h"

int	*sort2B(t_list *list)
{
	t_list	*Bfirst;
	int		*re;

	Bfirst = searchB_first(list);
	if(Bfirst->num < Bfirst->next->num)
	{
		re = malloc(sizeof(int) * 2);
		re[0] = SB;
		re[1] = END;
		do_inst_noput(list, SB);
	}
	else
	{
		re = malloc(sizeof(int));
		re[0] = END;
	}
	return(re);
}