#include "push_swap.h"

void	set_data(t_list *list, const char *argv, const int i)
{
	list->num = atoi(argv);
	list->order = i;
	list->a_b = A;
}

void	connect_startend(t_list *prev, t_list *start)
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
		set_data(list, argv[i + 1], i);
		list->next = malloc(sizeof(t_list) * 1);
		list->last = 0;
		list->a_b = 0;
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

t_list	*search_list(t_list *list, int order)
{
	t_list	*p;

	p = list;
	while(p->order != order)
		p = p->next;
	return(p);
}

t_list	*search_listnum(t_list *list, int num, int ab)
{
	t_list	*p;

	if(ab == A)
		p = search_list(list, search_Alast(list));
	else
		p = search_list(list, search_Blast(list));
	while(p->num != num && p->a_b == ab)
		p = p->prev;
	return(p);
}
/* 
int main(void)
{
	char argv[4][4] = {"", "123", "111", "1234"};
	
	make_list(4, argv);
	return(0);
} */