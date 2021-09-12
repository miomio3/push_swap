#include "push_swap.h"

int	judge_next(int *array1, int *array2)//int * でなく、intでも大丈夫？
{
	if(array1[0] == array2[0] - 3)
		return(array1[0] + 6);
	else
		return(CREATE2);
}

tree_node	*search_min(tree_node *tree)//movesの最小値を探索
{
	tree_node	*left;
	tree_node	*right;
	tree_node	*center;

	if(tree->fixed == FIXED)
	{
		left = search_min(tree->left);
		center = search_min(tree->right);
		if(tree->right != NULL)
			right = search_min(tree->right);
		else
			right = NULL;
		return(select_min_node(right,center, left));
	}
	else
		return(tree);
	
}

int	*dijk(int *array1, int *array2)//名前はまだない、ダイクストラ法
{
	tree_node	*tree;
	tree_node	*min;
	int			next_instruction;
	int			*array;
	int			array_size[2];
	int			f;

	tree = init_node(array1, array2);
	array_size[0] = count_array(array1);
	array_size[1] = count_array(array2);
	f = 1;
	while(f)
	{
		min = search_min(tree);
		if(min->remaining_array1 == 0 && min->remaining_array2 == 0)
			break;
		min->fixed = FIXED;//minと認定されて初めてFIXEDになる
		next_instruction = judge_next(&array1[array_size[0] - min->remaining_array1], &array2[array_size[1] - min->remaining_array2]);
		f = create_next(&min, next_instruction, array1[array_size[0] - min->remaining_array1], array2[array_size[1] - min->remaining_array2]);
	}
	//array = make_min_array(tree);
	//free_tree();
	return(array);
}

int	main(void)
{
	int	array1[4] = {RA, SA, RRA, END};
	int	array2[4] = {RB, SB, RB, END};
	dijk(array1, array2);
}