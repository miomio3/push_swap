#include "push_swap.h"

void	rrb(t_list *list, int put)
{
	t_list	*first;
	int		i;
	t_list	last;
	t_list	*p;

	first = searchB_first(list);
	p = search_list(list, 0)->prev;
	last = *p;
	i = p->order;
	while(i >= first->order)
	{
		if(i == first->order)
			assign_data(p, last.num, last.sorted, last.arrayorder, last.enst);
		else
			assign_prevdata(p);
		p = p->prev;
		i--;
	}
	if(put == PUT)
		ft_putstr("rrb\n");
}

void	rrr(t_list *list)
{
	rra(list, NOPUT);
	rrb(list, NOPUT);
	ft_putstr("rrr\n");
}

void	rr(t_list *list)
{
	ra(list, NOPUT);
	rb(list, NOPUT);
	ft_putstr("rr\n");
}

void	sa(t_list *list, int put)
{
	t_list	*pa;

	pa = searchA_last(list);
	swap_data(pa, pa->prev);
	if(put == PUT)
		ft_putstr("sa\n");
}

void	sb(t_list *list, int put)
{
	t_list	*pb;

	pb = searchB_first(list);
	swap_data(pb, pb->next);
	if(put == PUT)
		ft_putstr("sb\n");
}