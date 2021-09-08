#include "push_swap.h"

void	rr2sort(t_list *firstA, t_list *firstB)
{
	int	smaller;
	int	bigger;
	int	i;

	smaller = select_smaller(search_Alast(firstA)->order - firstA->order - 1, firstB->order - search_Blast(firstA)->order);
	bigger = select_bigger(search_Alast(firstA)->order - firstA->order - 1, firstB->order - search_Blast(firstA)->order);
	i = smaller;
	while(i--)
		ss_rr(firstA);
	i = bigger - smaller;
	if(bigger == firstB->order)
		while(i--)
			sb_rb(firstA);
	else
		while(i--)
			sa_ra(firstA);
}

void	rrr2sort(t_list *firstA, t_list *firstB)
{
	int	smaller;
	int	bigger;
	int	i;

	smaller = select_smaller(firstA->order + 1, search_last(firstA)->order - firstB->order - 1);
	bigger = select_bigger(firstA->order + 1, search_last(firstA)->order - firstB->order - 1);
	i = smaller;
	while(i--)
		ss_rr(firstA);
	i = bigger - smaller;
	if(bigger == search_last(firstA)->order - firstB->order - 1)
		while(i--)
			sb_rb(firstA);
	else
		while(i--)
			sa_ra(firstA);
}
void	rrbra2sort(t_list *firstA, t_list *firstB)
{
	int	i;

	i = search_Alast(firstA)->order - firstA->order - 1;
	while(i--)
		sa_ra(firstA);
	i = search_last(firstA)->order - firstB->order - 1;
	while(i--)
		sb_rrb(firstA);
}

void	rrarb2sort(t_list *firstA, t_list *firstB)
{
	int	i;

	i = firstA->order + 1;
	while(i--)
		sa_rra(firstA);
	i = firstB->order - search_Blast(firstA)->order;
	while(i--)
		sb_rb(firstA);
}