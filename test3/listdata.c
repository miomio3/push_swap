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
	a->sorted = b->sorted;
	b->sorted = tmp;
	tmp = a->arrayorder;
	a->arrayorder = b->arrayorder;
	b->arrayorder = tmp;
}

void	assign_nextdata(t_list *p)
{
	p->num = p->next->num;
	p->sorted = p->next->sorted;
	p->arrayorder = p->next->arrayorder;
}

void	assign_prevdata(t_list *p)
{
	p->num = p->prev->num;
	p->sorted = p->prev->sorted;
	p->arrayorder = p->prev->arrayorder;
}

void	assign_data(t_list *p, int num, int sorted, int arrayorder)
{
	p->num = num;
	p->sorted = sorted;
	p->arrayorder = arrayorder;
}

void	assign_out2(out2 *out, int instruction, t_list *a, t_list *b)
{
	out->instruction = instruction;
	out->pa = a;
	out->pb = b;
}
