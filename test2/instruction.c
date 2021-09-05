#include "push_swap.h"

void	ra(t_list *list, int put)
{
	t_list	*p;
	int		i;
	int		lastnum;
	int		lastsorted;

	p = search_Alast(list);
	i = p->order;
	lastnum = p->num;
	lastsorted = p->sorted;
	while(i >= 0)
	{
		if(i == 0)
		{
			p->num = lastnum;
			p->sorted = lastsorted;
		}
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
	int		firstnum;
	int		Alast;
	int		firstsorted;

	Alast = search_Alast(list)->order;
	p = search_list(list, 0);
	firstnum = p->num;
	firstsorted = p->sorted;
	i = 0;
	while(i <= Alast)
	{
		if(i == Alast)
		{
			p->num = firstnum;
			p->sorted = firstsorted;
		}
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
	int		firstnum;
	int		firstsorted;
	int		i;

	last = search_list(list, 0)->prev;
	p = search_Blast(list);
	firstnum = p->num;
	firstsorted = p->sorted;
	i = p->order;
	while(i <= last->order)
	{
		if(i == last->order)
			assign_data(p, firstnum, firstsorted);
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
