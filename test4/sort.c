#include "push_swap.h"

int	*create2re(int inst1, int inst2)
{
	int	*re;
	int	i;

	i = 0;
	if(inst1 == END)
		re = malloc(sizeof(int) * 1);
	else if(inst2 == END)
	{
		re = malloc(sizeof(int) * 2);
		re[i++] = inst1;
	}
	else
	{
		re = malloc(sizeof(int) * 3);
		re[i++] = inst1;
		re[i++] = inst2;
	}
	re[i] = END;
	return(re);
}

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
		i++;
	} 
	put_inst(instA, instB);
	free(instA);
	free(instB);
}