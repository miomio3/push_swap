#include "push_swap.h"

int	cost(tree_node *tree)
{
	return(tree->moves + tree->remaining_array1 + tree->remaining_array2);
}

tree_node	*select_min_node(tree_node *right, tree_node *center, tree_node *left)
{
	tree_node	*min;

	min = left;
	if(right != NULL)
		if(cost(right) < cost(left))
			min = right;
	if(cost(min) > cost(center))
		min = center;
	return(min);
}

int	count_remaining_array1(tree_node *tree, int inst)
{
	if(inst == RR || inst == RRR || inst == SS)
			return(tree->remaining_array1 - 1);
	else
	{
		if(inst == RA || inst == RRA || inst == SA)
			return(tree->remaining_array1 - 1);
		else
			return(tree->remaining_array1);
	}
}

int	count_remaining_array2(tree_node *tree, int inst)
{
	if(inst == RR || inst == RRR || inst == SS)
			return(tree->remaining_array2 - 1);
	else
	{
		if(inst == RB || inst == RRB || inst == SB)
			return(tree->remaining_array2 - 1);
		else
			return(tree->remaining_array2);
	}
}
