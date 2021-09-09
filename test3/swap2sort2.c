#include "push_swap.h"

void	rr2sort(t_list *firstA, t_list *firstB)
{
	int	smaller;
	int	bigger;
	int	i;

	smaller = select_smaller(ra2top_times(firstA), rb2top_times(firstB) - 1);
	bigger = select_bigger(ra2top_times(firstA), rb2top_times(firstB) - 1);
	i = smaller;
	while(i--)
		ss_rr(firstA);
	i = bigger - smaller;
	if(bigger == rb2top_times(firstB) - 1)
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

	smaller = select_smaller(rra2top_times(firstA) - 1, rrb2top_times(firstB));
	bigger = select_bigger(rra2top_times(firstA) - 1, rrb2top_times(firstB));
	i = smaller;
	while(i--)
		rrr_ss(firstA);
	i = bigger - smaller;
	if(bigger == rrb2top_times(firstB))
		while(i--)
			rrb_sb(firstA);
	else
		while(i--)
			rra_sa(firstA);
}
void	rrbra2sort(t_list *firstA, t_list *firstB)
{
	int	i;

	i = ra2top_times(firstA);
	while(i--)
		sa_ra(firstA);
	i = rrb2top_times(firstB);
	while(i--)
		rrb_sb(firstA);
}

void	rrarb2sort(t_list *firstA, t_list *firstB)
{
	int	i;

	i = rra2top_times(firstA) - 1;
	while(i--)
		rra_sa(firstA);
	i = rb2top_times(firstB) - 1;
	while(i--)
		sb_rb(firstA);
}