#include "push_swap.h"

int	*sort2A(t_list *list)
{
	t_list	*Alast;
	int		*re;

	Alast = searchA_last(list);
	if(Alast->num > Alast->prev->num)
	{
		re = malloc(sizeof(int) * 2);
		re[0] = SA;
		re[1] = END;
		do_inst_noput(list, SA);
	}
	else
	{
		re = malloc(sizeof(int));
		re[0] = END;
	}
	return(re);
}