#include "push_swap.h"

int	*ra2top(t_list *list, int put)
{
	int	i;
	int	*array;

	i = ra2top_times(list);
	array = malloc(sizeof(int) * i + 2);
	array[i] = END;
	while(i--)
	{
		ra(list, put);
		array[i] = RA;
	}
	return(array);
}

int	*rra2top(t_list *list, int put)
{
	int	i;
	int	*array;

	i = rra2top_times(list);
	array = malloc(sizeof(int) * i + 2);
	array[i] = END;
	while(i--)
	{
		rra(list, put);
		array[i] = RRA;
	}
	return(array);
}