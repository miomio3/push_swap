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

void	rrr_ss(t_list *list)
{
	rrr(list);
	ss(list);
}

void	rra_sa(t_list *list)
{
	rra(list, PUT);
	sa(list, PUT);
}

void	rrb_sb(t_list *list)
{
	rrb(list, PUT);
	sb(list, PUT);
}