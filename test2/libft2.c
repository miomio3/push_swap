#include "push_swap.h"
/* 
int	absolute_value(int num)
{
	if(num < 0)
		num = num * (-1);
	return(num);
}
 */
void	delarray_fromlast(int *array, int max_array, int num)
{
	int	i;

	i = 0;
	while(array[max_array - i - 1] != num && max_array - i - 1 <= max_array)
		i++;
	if(max_array - i - 1 <= max_array)
	{
		while(&array[max_array - i - 1] != &array[max_array])
		{
			array[max_array - i - 1] = array[max_array - i];
			i--;
		}
	}
}
/* 
void	delarray_from0(int *array, int max_array, int num)
{
	int	i;

	i = 0;
	while(array[i] != num && i <= max_array)
		i++;
	if(i <= max_array)
	{
		while(&array[i] != &array[max_array])
		{
			array[i] = array[i + 1];
			i++;
		}
	}
}
 */