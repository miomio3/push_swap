#include "push_swap.h"

typedef struct tree_node
{
	int	moves;
	int	op;
	int remaining_array1;
	int	remaining_array2;
	struct tree_node *right;
	struct tree_node *center;
	struct tree_node *left;
	struct tree_node *prev;
}tree_node;

tree_node	*select_min_node(tree_node *right, tree_node *left)
{
	if(right->moves > left->moves)
		return(left);
	else
		return(right);
}

int	count_treed_array(tree_node *tree, int inst, int No)
{
	if(inst == RR || inst == RRR || inst == SS)
	{
		if(No == 1)
			return(tree->remaining_array1 - 2);
		else
			return(tree->remaining_array2 - 2);
	}
	else
	{
		if(No == 1)
			return(tree->remaining_array1 - 1);
		else
			return(tree->remaining_array2 - 1);
	}
}

tree_node	*set_node(tree_node **tree, int inst)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node *));
	node->moves = (*tree)->moves + 1;
	node->op = inst;
	node->right = NULL;
	node->left = NULL;
	node->center = NULL;
	node->prev = *tree;
	node->moves = 0;
	node->remaining_array1 = count_treed_array(*tree, inst, 1);
	node->remaining_array2 = count_treed_array(*tree, inst, 2);
}

void	create_double(tree_node **tree, int inst)
{
	tree_node	*next;

	if((*tree)->left != NULL)
		(*tree)->left = ;
	else if((*tree)->center != NULL)
		(*tree)->center = malloc(sizeof(tree_node *));
	else

}

int	judge_next(int *array1, int *array2)
{
	if(array1[0] == END)
		return(array2[0]);
	else if(array2[0] == END)
		return(array1[0]);
	else if(array1[0] == array2[0] - 3)
		return(array1[0] + 6);
	else
		return(CREATE2);
}

void	create_next(tree_node **min, int inst, int *array1, int *array2)
{
	tree_node	*node;

	if(inst == RR || inst == RRR || inst == SS)
		create_double(min, inst);
/* 	else if(inst == CREATE2)
		create2(min, array1, array2);
	else
		create1(min, inst); */
}

tree_node	*search_min(tree_node *tree)//movesの最小値を探索
{
	tree_node	*left;
	tree_node	*right;

	if(tree->right != NULL)
		right = search_min(tree->right);
	else
		right = tree;
	if(tree->right != NULL)
		left = search_min(tree->left);
	else
		left = tree;
	return(select_min_node(right, left));
}

int	*dijk(int *array1, int *array2)//名前はまだない、ダイクストラ法
{
	tree_node	*tree;
	tree_node	*min;
	int			next_instruction;
	int			f;
	int			*array;

	set_node(&tree, FIRST);
	tree->remaining_array1 = count_array(array1);
	tree->remaining_array2 = count_array(array2);
	f = 1;
	while(f)
	{
		min = search_min(tree);
		next_instruction = judge_next(&array1[min->remaining_array1], &array2[min->remaining_array2]);
		//f = create_next(&min, next_instruction, &array1[min->treed_array1], &array2[treed_array2]);//最終が見つかったらf = 0
	}
	//array = make_min_array(tree);
	//free_tree();
	//return(array);
}

int	main(void)
{
	int	array1[4] = {RA, SA, RRA, END};
	int	array2[4] = {RB, SB, RB, END};
	dijk(array1, array2);
}