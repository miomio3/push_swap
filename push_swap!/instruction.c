#include "push_swap.h"

void	ra(t_list *list, int put)
{
	t_list	*p;
	int		i;
	t_list	last;

	p = searchA_last(list);
	i = p->order;
	last = *p;
	while(i >= 0)
	{
		if(i == 0)
			assign_data(p, last);
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

	Alast = searchA_last(list)->order;
	p = search_list(list, 0);
	first = *p;
	i = 0;
	while(i <= Alast)
	{
		if(i == Alast)
			assign_data(p, first);
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
	p = searchB_first(list);
	first = *p;
	i = p->order;
	while(i <= last->order)
	{
		if(i == last->order)
			assign_data(p, first);
		else
			assign_nextdata(p);
		p = p->next;
		i++;
	}
	if(put == PUT)
		ft_putstr("rb\n");
}

void	pb(t_list *list, int put)
{
	t_list	*p;
	t_list	*prev;

	p = searchA_last(list);
	prev = search_prev(p, A);
	if(put == PUT)
		ft_putstr("pb\n");
	if(p->enst == START)
	{
		search_next(p, A)->enst = START;
		p->enst = NOTHING;
		p->a_b = B;
	}
	else if(p->enst == END)
	{
		if(prev->enst != START)
			prev->enst = END;
		p->enst = NOTHING;//pのenstをいじりたい場合はpbした後
		p->a_b = B;
	}
	else
		p->a_b = B;
}

void	pa(t_list *list, int put)
{
	t_list	*p;

	p = searchB_first(list);
	p->a_b = A;
	if(put == PUT)
		ft_putstr("pa\n");
}
