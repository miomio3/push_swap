#include "push_swap.h"

void	ss_rr(t_list *list)
{
	ss(list);
	rr(list);
}

void	sa_ra(t_list *list)
{
	sa(list, PUT);
	ra(list, PUT);
}

void	sb_rb(t_list *list)
{
	sb(list, PUT);
	rb(list, PUT);
}

void	sa_rra(t_list *list)
{
	sa(list, PUT);
	rra(list, PUT);
}

void	sb_rrb(t_list *list)
{
	sb(list, PUT);
	rrb(list, PUT);
}