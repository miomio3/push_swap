#include "push_swap.h"

int	comp01A(t_list *list)
{
	t_list	*zero;
	t_list	*first;

	zero = searchA_last(list);
	first = zero->prev;
	if(zero->num > first->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	comp02A(t_list *list)
{
	t_list	*zero;
	t_list	*second;

	zero = searchA_last(list);
	second = zero->prev->prev;
	if(zero->num > second->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	comp12A(t_list *list)
{
	t_list	*first;
	t_list	*second;

	first = searchA_last(list)->prev;
	second = first->prev;
	if(first->num > second->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	*sort3A(t_list *list)
{
	int	comp01;
	int	comp02;
	int	comp12;
	int	*re;
	int	i;

	comp01 = comp01A(list);
	comp02 = comp02A(list);
	comp12 = comp12A(list);
	if(comp01 == NOSORTED && comp02 == NOSORTED && comp12 == NOSORTED)
		re = create2re(SA, RRA);
	else if(comp01 == NOSORTED && comp02 == NOSORTED)
		re = create2re(RA, END);
	else if(comp02 == NOSORTED && comp12 == NOSORTED)
		re = create2re(RRA, END);
	else if(comp01 == NOSORTED)
		re = create2re(SA, END);
	else if(comp12 == NOSORTED)
		re = create2re(SA, RA);
	else
		re = create2re(END, END);
	i = -1;
	while(re[++i] != END)
		do_inst_noput(list, re[i]);
	return(re);
}

int	*sortA_first(t_list *list)
{
	int	count;
	int	*re;

	count = countA(list);
	if(count == 2)
		re = sort2A(list);
	else if(count == 3)
		re = sort3A(list);
	else
	{
		re = malloc(sizeof(int));
		re[0] = END;
	}
	return(re);
}