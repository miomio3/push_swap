#include "push_swap.h"

static void	set_data(t_list *list, const char *argv, t_list *prev, const int i)
{
	list->num = atoi(argv);
	list->order = i;
	list->a_b = A;
	list->last = 0;
	list->a_b = 0;
	list->sorted = 0;
	list->enst = NOTHING;
	if(prev != NULL)
	{
			list->prev = prev;
			prev->next = list;
	}
}

static void	connect_startend(t_list *prev, t_list *start)
{
	prev->last = 1;
	prev->next = start;
	start->prev = prev;
}

t_list	*make_list(int argc, char *argv[])
{
	int		i;
	t_list	*start;
	t_list	*prev;
	t_list	*list;

	i = 0;
	prev = NULL;
	while(i < argc - 1)
	{
		list = malloc(sizeof(t_list) * 1);
		set_data(list, argv[argc - 1 - i], prev, i);
		if(i == 0)
		{
			start = list;
			list->enst = START;
		}
		else if(i == argc - 2)
			list->enst = END;
		prev = list;
		list = list->next;
		i++;
	}
	connect_startend(prev, start);
	return(prev->next);
}

void	free_list(t_list *list)
{
	t_list	*p;
	t_list	*t;
	int		i;

	p = list;
	i = 0;
	while(p != list || i++ == 0)
	{
		t = p->next;
		free(p);
		p = NULL;
		p = t;
	}
}

int	smallest_distance2topB(t_list *list)
{
	int	distance0;
	int	distancelast;
	distance0 = list->order - searchB_first(list)->order;
	distancelast = list->order + 1;
	if(distance0 < distancelast)
		return(distance0);
	else
		return(distancelast);
}
/* 
int main(void)
{
	t_list *list;
	char *argv[3] = {"1353271128", "-1941500750","-1627890091"};

	list = make_list(3, argv);
	free_list(list);
	return(0);
} */