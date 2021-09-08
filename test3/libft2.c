#include "push_swap.h"

void	delarray_fromlast(int *array, int max_array, int num)
{
	int	i;

	i = 0;
	while(i < max_array)
	{
		if(array[max_array - i - 1] == num)
			break;
		i++;
	}
	while(max_array - i - 1 < max_array)
	{
		array[max_array - i - 1] = array[max_array - i];
		i--;
	}
}
