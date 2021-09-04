#include "push_swap.h"

void	ra(t_list *list)
{
	t_list	*p;
	int		i;
	int		lastnum;
	int		Alast;

	Alast = search_Alast(list);
	p = search_list(list, Alast);
	i = Alast;
	lastnum = p->num;
	while(i >= 0)
	{
		if(i == 0)
			p->num = lastnum;
		else
			p->num = p->prev->num;
		p = p->prev;
		i--;
	}
	ft_putstr("ra\n");
}

void	rra(t_list *list)
{
	t_list	*p;
	int		i;
	int		firstnum;
	int		Alast;

	Alast = search_Alast(list);
	p = search_list(list, 0);
	firstnum = p->num;
	i = 0;
	while(i <= Alast)
	{
		if(i == Alast)
			p->num = firstnum;
		else
			p->num = p->next->num;
		p = p->next;
		i++;
	}
	ft_putstr("rra\n");
}

void	pb(t_list *list)
{
	t_list	*p;

	p = search_list(list, search_Alast(list));
	p->a_b = B;
	ft_putstr("pb\n");
}

void	pa(t_list *list)
{
	t_list	*p;

	p = search_list(list, search_Blast(list));
	p->a_b = A;
	ft_putstr("pa\n");
}
