#include "push_swap.h"

void	push2topB(t_list *p)
{
	int	last;

	last = search_Blast(p)->order;
	if(p->order > last / 2)
	{
		while(p->order != last)
		{
			rrb(p, PUT);
			p = search_next(p, B);
		}
	}
	else
	{
		while(p->order != last)
		{
			rb(p, PUT);
			p = p->prev;
		}
	}
}

void	swap2sortB(t_list *p)
{
	int	sorted_order;
	int	p_order;
	int	i;

	sorted_order = search_firstsorted(p, B)->order;
	p_order = p->order;
	i = 0;
	while(i <  sorted_order - p_order - 1)
	{
		sb(p, PUT);
		rb(p, PUT);
		i++;
	}
}

void	sortB(t_list *list, int *array, int argc, int nowi)
{
	int		i;
	t_list	*p;

	i = nowi;
	while(i < PUSH2B)
	{
		p = search_num_nosorted_from0(list, array[argc - 2 - i], B);
		push2topB(p);
		swap2sortB(p);
		search_Blast(p)->sorted = SORTED;
		i++;
	}
}