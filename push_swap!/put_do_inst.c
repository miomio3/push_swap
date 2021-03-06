#include "push_swap.h"

void	ft_putstr_inst(int inst)
{
	if(inst == RA)
		ft_putstr("ra\n");
	else if(inst == RB)
		ft_putstr("rb\n");
	else if(inst == RRA)
		ft_putstr("rra\n");
	else if(inst == RRB)
		ft_putstr("rrb\n");
	else if(inst == RR)
		ft_putstr("rr\n");
	else if(inst == RRR)
		ft_putstr("rrr\n");
	else if(inst == SA)
		ft_putstr("sa\n");
	else if(inst == SB)
		ft_putstr("sb\n");
	else if(inst == SS)
		ft_putstr("ss\n");
	else if(inst == PA)
		ft_putstr("pa\n");
	else if(inst == PB)
		ft_putstr("pb\n");
	else if(inst == PP)
		ft_putstr("pp\n");
}

void	put_inst1(int *inst)
{
	int	i;

	if(inst == NULL)
		return;
	i = 0;
	while(inst[i] != END)
	{
		ft_putstr_inst(inst[i]);
		i++;
	}
}

void	put_inst(int *instA, int *instB)
{
	put_inst1(instA);
	put_inst1(instB);
}

void	do_inst_noput(t_list *list,int inst)
{
	if(inst == RA)
		ra(list, NOPUT);
	else if(inst == RRA)
		rra(list, NOPUT);
	else if(inst ==RB)
		rb(list, NOPUT);
	else if(inst == RRB)
		rrb(list, NOPUT);
	else if(inst == RR)
		rr(list, NOPUT);
	else if(inst == RRR)
		rrr(list, NOPUT);
	else if(inst == SA)
		sa(list, NOPUT);
	else if(inst == SB)
		sb(list, NOPUT);
	else if(inst == SS)
		ss(list, NOPUT);
}