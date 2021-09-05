#include "push_swap.h"

void	rrb(t_list *list, int put)
{
	t_list	*first;
	int		i;
	int		lastnum;
	int		lastsorted;
	t_list	*p;

	first = search_Blast(list);
	p = search_list(list, 0)->prev;
	lastnum = p->num;
	lastsorted = p->sorted;
	i = p->order;
	while(i >= first->order)
	{
		if(i == first->order)
			assign_data(p, lastnum, lastsorted);
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

void	rrarb2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	i;

	i = pa->order + 1;
	while(i--)
		rra(pa, PUT);
	i = pb->order - Blast;
	while(i--)
		rb(pb, PUT);
}

void	rrbra2top(t_list *pa, t_list *pb, int Alast, int Blast)
{
	int	i;

	i = Alast - pa->order;
	while(i--)
		ra(pa, PUT);
	i = search_last(pb)->order - pb->order + 1;
	while(i--)
		rrb(pb, PUT);
}