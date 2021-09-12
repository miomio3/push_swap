#include "push_swap.h"

int	create_double(tree_node **min, int inst, int array1_inst, int array2_inst)
{
	tree_node	*left;

	left =  create_node(min, inst);
	(*min)->left =left;
	(*min)->center = create_node(min, array1_inst);
	(*min)->right = create_node(min, array2_inst);
	if(left->remaining_array1 == 0 && left->remaining_array2 == 0)
		return(END);
	else
		return(CONTINUE);
}

int	create_next(tree_node **min, int inst, int array1_inst, int array2_inst)
{
	tree_node	*node;
	int f;

	if(inst == RR || inst == RRR || inst == SS)
		f = create_double(min, inst, array1_inst, array2_inst);
	else
		f = create2(min, array1_inst, array2_inst);//途中
	return(f);
}

tree_node	*create_node(tree_node **tree, int inst)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node *));
	node->moves = (*tree)->moves + 1;
	node->op = inst;
	node->right = NULL;
	node->left = NULL;
	node->center = NULL;
	node->fixed = NOFIXED;
	node->prev = *tree;
	node->remaining_array1 = count_remaining_array1(*tree, inst);
	node->remaining_array2 = count_remaining_array2(*tree, inst);
	return(node);
}
