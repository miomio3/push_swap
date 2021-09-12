#include "push_swap.h"

int	count_array(int *array)
{
	int	i;

	i = 0;
	while(array[i] != END)
		i++;
	return(i);
}

int	select_bigger_num(int num1, int num2)
{
	if(num1 < num2)
		return(num2);
	else
		return(num1);
}
