#include "push_swap.h"

int	cost(tree_node *tree)
{
	return(tree->moves + tree->remaining_array1 + tree->remaining_array2);
}

tree_node	*select_min_node(tree_node *right, tree_node *center, tree_node *left)
{
	tree_node	*min;

	if(right != NULL)
		if(cost(right) < cost(left))
			min = right;
	else
		min = right;
	if(cost(min) > cost(center))
		min = center;
	return(min);
}

tree_node	*init_node(int *array1, int *array2)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node *));
	node->moves = 0;
	node->op = FIRST;
	node->right = NULL;
	node->left = NULL;
	node->center = NULL;
	node->prev = NULL;
	node->moves = 0;
	node->fixed = NOFIXED;
	node->remaining_array1 = count_array(array1);
	node->remaining_array2 = count_array(array2);
	return(node);
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
