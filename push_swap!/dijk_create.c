#include "push_swap.h"

int	create_double(tree_node *min, int inst, int array1_inst, int array2_inst)
{
	tree_node	*left;

	left =  create_node(min, inst);
	if(left == NULL)
		return(ERROR);
	min->left =left;
	min->center = create_node(min, array1_inst);
	if(min->center == NULL)
		return(ERROR);
	min->right = create_node(min, array2_inst);
	if(min->right == NULL)
		return(ERROR);
	if(is_remaining_array(min->left) == NOEXIST || is_remaining_array(min->center) == NOEXIST || is_remaining_array(min->right) == NOEXIST)
		return(END);
	else
		return(CONTINUE);
}

int	create_next(tree_node *min, int inst, int array1_inst, int array2_inst)
{
	int f;

	if(inst == RR || inst == RRR || inst == SS || inst == PP)
		f = create_double(min, inst, array1_inst, array2_inst);
	else
		f = create_only2(min, array1_inst, array2_inst);
	return(f);
}

tree_node	*create_node(tree_node *tree, int inst)
{
	tree_node	*node;

	node = NULL;
	node = malloc(sizeof(tree_node));
	if(node == NULL)
		return(NULL);
	node->moves = tree->moves + 1;
	node->op = inst;
	node->right = NULL;
	node->left = NULL;
	node->center = NULL;
	node->fixed = NOFIXED;
	node->prev = tree;
	node->remaining_array1 = count_remaining_array1(tree, inst);
	node->remaining_array2 = count_remaining_array2(tree, inst);
	return(node);
}

int	create_only2(tree_node *min, int array1_inst, int array2_inst)
{
	tree_node	*left;

	left =  create_node(min, array1_inst);
	min->left =left;
	min->center = create_node(min, array2_inst);
	if(is_remaining_array(min->left) == NOEXIST || is_remaining_array(min->center) == NOEXIST)
		return(END);
	else
		return(CONTINUE);
}

tree_node	*init_node(int *array1, int *array2)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node));
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