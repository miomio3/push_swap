#include "push_swap.h"

void	ra(t_list *list, int argc)
{
	t_list	*p;
	int		i;
	int		first;

	p = search_list(list, 0);
	argc = search_other(list, B);
	while(p->a_b != A)
		p = p->next;
	i = p->order;
	first = p->order;
	while(i < argc - 1)
	{
		if(i == first)
			p->order = argc - 2;
		else
			p->order = i - 1;
		p = p->next;
		i++;
	}
	ft_putstr("ra\n");
}

void	rra(t_list *list, int argc)
{
	t_list	*p;
	int		i;
	int		first;

	p = search_list(list, 0);
	while(p->a_b != A)
		p = p->next;
	i = p->order;
	first = p->order;
	while(i < argc - 1)
	{
		if(i == argc - 2)
			p->order = first;
		else
			p->order = i + 1;
		p = p->next;
		i++;
	}
	ft_putstr("rra\n");
}

void	pb(t_list *list, int argc)
{
	t_list	*p;

	p = search_list(list, argc - 2);
	while(p->a_b != A)
		p = p->prev;
	p->a_b = B;
	ft_putstr("pb\n");
}