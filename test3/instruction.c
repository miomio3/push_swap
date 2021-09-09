#include "push_swap.h"

void	ra(t_list *list, int put)
{
	t_list	*p;
	int		i;
	t_list	last;

	p = search_Alast(list);
	i = p->order;
	last = *p;
	while(i >= 0)
	{
		if(i == 0)
			assign_data(p, last.num, last.sorted, last.arrayorder);
		else
			assign_prevdata(p);
		p = p->prev;
		i--;
	}
	if(put == PUT)
		ft_putstr("ra\n");
}

void	rra(t_list *list, int put)
{
	t_list	*p;
	int		i;
	int		Alast;
	t_list	first;

	Alast = search_Alast(list)->order;
	p = search_list(list, 0);
	first = *p;
	i = 0;
	while(i <= Alast)
	{
		if(i == Alast)
			assign_data(p, first.num, first.sorted, first.arrayorder);
		else
			assign_nextdata(p);
		p = p->next;
		i++;
	}
	if(put == PUT)
		ft_putstr("rra\n");
}

void	rb(t_list *list, int put)
{
	t_list	*p;
	t_list	*last;
	t_list	first;
	int		i;

	last = search_list(list, 0)->prev;
	p = search_Blast(list);
	first = *p;
	i = p->order;
	while(i <= last->order)
	{
		if(i == last->order)
			assign_data(p, first.num, first.sorted, first.arrayorder);
		else
			assign_nextdata(p);
		p = p->next;
		i++;
	}
	if(put == PUT)
		ft_putstr("rb\n");
}

void	pb(t_list *list)
{
	t_list	*p;

	p = search_Alast(list);
	p->a_b = B;
	ft_putstr("pb\n");
}

void	pa(t_list *list)
{
	t_list	*p;

	p = search_Blast(list);
	p->a_b = A;
	ft_putstr("pa\n");
}
