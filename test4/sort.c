#include "push_swap.h"

static int	*make_int(t_list *list, int argc)
{
	int		i;
	int		*array;
	t_list	*p;

	array = malloc(sizeof(int) * argc - 1);
	p = list;
	i = 0;
	while(i < argc - 1)
	{
		array[i] = p->num;
		p->arrayorder = i;
		p = p->next;
		i++;
	}
	return(array);
}

void	sort(t_list *list, int argc)
{
	int	*array;

	array = make_int(list, argc);
	bouble(array, argc, list);
	//quick();
	free(array);
}