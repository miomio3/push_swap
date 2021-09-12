#include "push_swap.h"


int	count_array(int *array)
{
	int	i;

	i = 0;
	while(array[i] != END)
		i++;
	return(i);
}
