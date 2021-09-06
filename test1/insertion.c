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

void	push2b(t_list *list, int pushnum, int Alast)
{
	t_list	*p;

	p = search_listnum(list, pushnum, A);
	if(p->order < Alast / 2)
	{
		while(p->order != Alast)
		{
			if(p->order == 0)
				p = search_list(list, search_Alast(list));
			else
				p = p->prev;
			rra(list);
		}
	}
	else
	{
		while(p->order != Alast)
		{
			p = p->next;
			ra(list);
		}
	}
	if(is_sorted(list) == -1)
		pb(list);
}

int	insertion(t_list *list, int argc)
{
	int	*array;
	int	i;

	array = make_int(list, argc);
	bouble(array, argc);
	i = 0;
	while(is_sorted(list) == -1)
	{
		push2b(list, array[i], search_Alast(list));
		i++;
	}
	while(is_B(list) == 1)
		pa(list);
	return(0);
}

int	main()//int argc, char **argv)
{
	t_list	*list;
	int i;

	char *argv[8] = {"", "1", "-1941500750","-1627890091", "111", "-1", "11", "1"};
	list = make_list(8, argv);
	insertion(list, 8);
	return(0);
}