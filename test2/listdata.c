#include "push_swap.h"

void	swap_data(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
	tmp = a->a_b;
	a->a_b = b->a_b;
	b->a_b = tmp;
	tmp = a->sorted;
	a->a_b = b->a_b;
	b->a_b = tmp;
}

void	assign_nextdata(t_list *p)
{
	p->num = p->next->num;
	p->sorted = p->next->sorted;
}

void	assign_prevdata(t_list *p)
{
	p->num = p->prev->num;
	p->sorted = p->prev->sorted;
}

void	assign_data(t_list *p, int num, int sorted)
{
	p->num = num;
	p->sorted = sorted;
}