#include "push_swap.h"

int	is_array(t_list *list, int *array, int arraysize)
{
	int	i;

	i = 0;
	while(list->num != array[i] && i < arraysize)
		i++;
	if(list->num == array[i])
		return(EXIST);
	else
		return(NOEXIST);
}