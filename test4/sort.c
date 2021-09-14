#include "push_swap.h"

void	sort_both(t_list *list)
{
	int	*instA;
	int	*instB;
	int	i;

	instA = sortA(list);
	instB = sortB(list);
	i = 0;
	while(instB[i] != END)
	{
		if(instB[i] == instA[0] + 4)
		{
			instB[i] = instB[i] + 4;
			instA[0] = END;
		}
	} 
	put_inst(instA, instB);
	free(instA);
	free(instB);
}