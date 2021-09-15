#include "push_swap.h"

int	*sortA(t_list *list)
{
	int	count;
	int	*array;

	array = NULL;
	count = countA(list);
	if(count == 2)
		array = sort2A(list);
	else
	{
		array = malloc(sizeof(int));
		array[0] = END;
	}
	return(array);
}