#include "push_swap.h"

void	set_data(t_list *list, const char *argv, const int i)
{
	list->num = atoi(argv);
	list->order = i;
	list->a_b = A;
}

void	connect_startend(t_list *prev, t_list *start)
{
	prev->next = start;
	start->prev = prev;
}

void	prev_next(t_list **list, t_list *prev)
{
	
}

t_list	*make_list(int argc, char argv[4][4])
{
	size_t	i;
	t_list	*start;
	t_list	*prev;
	t_list	*list;

	i = 0;
	list = malloc(sizeof(t_list) * 1);
	while(i < argc - 1)
	{
		set_data(list, argv[i + 1], i);
		list->next = malloc(sizeof(t_list) * 1);
		if(i == 0)
			start = list;
		prev = list;
		list = list->next;
		list->prev = prev;
		i++;
	}
	connect_startend(prev, start);
	return(list->prev->next);
}

int main(void)
{
	char argv[4][4] = {"", "123", "111", "1234"};
	
	make_list(4, argv);
	return(0);
}