#include "push_swap.h"

void	push2topA(t_list *p)
{
	int	last;

	last = search_Alast(p)->order;
	if(p->order > last / 2)
	{
		while(p->order != last)
		{
			ra(p, PUT);
			p = p->next;
		}
	}
	else
	{
		while(p->order != last)
		{
			rra(p, PUT);
			p = search_prev(p, A);
		}
	}
}

void	swap2sortA(t_list *p)
{
	int	sorted_order;
	int	p_order;
	int	i;

	sorted_order = search_firstsorted(p, A)->order;
	p_order = p->order;
	i = 0;
	while(i < p_order - sorted_order - 1)
	{
		sa(p, PUT);
		ra(p, PUT);
		i++;
	}
}

void	sortA(t_list *list, int *array, int argc, int nowi)
{
	int		i;
	t_list	*p;

	i = nowi;
	while(i < argc - 1 - PUSH2B)
	{
		p = search_num_nosorted_from0(list, array[i], A);
		push2topA(p);
		swap2sortA(p);
		search_Alast(p)->sorted = SORTED;
		i++;
	}
}
