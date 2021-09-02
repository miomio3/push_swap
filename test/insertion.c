#include "push_swap.h"

int	*make_int(t_list *list, int argc)
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
		p = p->next;
		i++;
	}
	return(array);
}

void	push2b(t_list *list, int argc)
{
	if(list->order > (argc - 1) / 2)
		while(list->order != argc - 2)
			rra(list, argc);
	else
		while(list->order != argc - 2)
			ra(list, argc);
	pb(list, argc);
}

int	insertion(t_list *list, int argc)
{
	int	*array;
	int	i;

	array = make_int(list, argc);
	bouble(array, argc);
	i = 0;
	while(i < argc)
	{
		push2b(search_listnum(list, array[ argc - 2 - i]), argc);
		i++;
	}
	return(0);
}

int	main(void)
{
	char *argv[4] = {"", "123", "111", "1234"};
	t_list	*list;

	list = make_list(4, argv);
	insertion(list, 4);
}