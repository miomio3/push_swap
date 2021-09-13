#include "push_swap.h"

int	cost(tree_node *tree)
{
	int	bigger;

	bigger = select_bigger_num(tree->remaining_array1, tree->remaining_array2);
	return(tree->moves + bigger);
}

int	count_remaining_array1(tree_node *tree, int inst)
{
	if(inst == RR || inst == RRR || inst == SS || inst == PP)
			return(tree->remaining_array1 - 1);
	else
	{
		if(inst == RA || inst == RRA || inst == SA || inst == PB)
			return(tree->remaining_array1 - 1);
		else
			return(tree->remaining_array1);
	}
}

int	count_remaining_array2(tree_node *tree, int inst)
{
	if(inst == RR || inst == RRR || inst == SS || inst == PP)
			return(tree->remaining_array2 - 1);
	else
	{
		if(inst == RB || inst == RRB || inst == SB || inst == PA)
			return(tree->remaining_array2 - 1);
		else
			return(tree->remaining_array2);
	}
}

int	count_array(int *array)
{
	int	i;

	i = 0;
	while(array[i] != END)
		i++;
	return(i);
}