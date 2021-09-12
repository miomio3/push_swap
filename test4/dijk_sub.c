#include "push_swap.h"

int	*make_min_array(tree_node *min)
{
	int	*array;
	int	i;
	int	last;

	last = min->moves;
	array = malloc(sizeof(int) * last + 1);
	i = 0;
	array[last] = END;
	while(min->op != FIRST)
	{
		array[last - i - 1] = min->op;
		min = min->prev;
		i++;
	}
	return(array);
}

void	free_tree(tree_node *tree)
{
	if(tree->left != NULL)
		free_tree(tree->left);
	if(tree->center != NULL)
		free_tree(tree->center);
	if(tree->right != NULL)
		free_tree(tree->right);
	free(tree);
	tree = NULL;
}

tree_node	*select_min_node(tree_node *right, tree_node *center, tree_node *left)
{
	tree_node	*min;

	if(is_remaining_array(left) == NOEXIST)
		return(left);
	if(is_remaining_array(center) == NOEXIST)
		return(center);
	if(is_remaining_array(right) == NOEXIST)
		return(right);
	min = select_min_in2(right, center);
	min = select_min_in2(min, left);
	return(min);
}

tree_node	*select_min_in2(tree_node *node1, tree_node *node2)
{
	if(node1 == NULL)
		return(node2);
	else if(node2 == NULL)
		return(node1);
	else
	{
		if(cost(node1) > cost(node2))
			return(node2);
		return(node1);
	}
}