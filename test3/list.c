#include "push_swap.h"

static void	set_data(t_list *list, const char *argv, const int i)
{
	list->num = atoi(argv);
	list->order = i;
	list->a_b = A;
	list->last = 0;
	list->a_b = 0;
	list->sorted = 0;
}

static void	connect_startend(t_list *prev, t_list *start)
{
	prev->last = 1;
	prev->next = start;
	start->prev = prev;
}

t_list	*make_list(int argc, char **argv)
{
	int		i;
	t_list	*start;
	t_list	*prev;
	t_list	*list;

	i = 0;
	list = malloc(sizeof(t_list) * 1);
	while(i < argc - 1)
	{
		set_data(list, argv[argc - 1 - i], i);
		list->next = malloc(sizeof(t_list) * 1);
		if(i == 0)
			start = list;
		prev = list;
		if(i != argc -2)
		{
			list = list->next;
			list->prev = prev;
		}
		i++;
	}
	connect_startend(prev, start);
	return(list->next);
}

void	free_list(t_list *list)
{
	t_list	*p;
	t_list	*t;
	int		i;

	p = list;
	i = search_last(list)->order + 1;
	while(i--)
	{
		t = p->next;
		free(p);
		p = NULL;
		p = t;
	}
}

/*
int main(void)
{
	char argv[4][4] = {"1353271128", "-1941500750","-1627890091"};
	
	make_list(4, argv);
	return(0);
} */