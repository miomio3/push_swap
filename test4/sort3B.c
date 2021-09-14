#include "push_swap.h"

int	comp01B(t_list *list)
{
	t_list	*zero;
	t_list	*first;

	zero = searchB_first(list);
	first = zero->next;
	if(zero->num < first->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	comp02B(t_list *list)
{
	t_list	*zero;
	t_list	*second;

	zero = searchB_first(list);
	second = zero->next->next;
	if(zero->num < second->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	comp12B(t_list *list)
{
	t_list	*first;
	t_list	*second;

	first = searchB_first(list)->next;
	second = first->next;
	if(first->num < second->num)
		return(NOSORTED);
	else
		return(SORTED);
}

int	*create2re(int inst1, int inst2)
{
	int	*re;
	int	i;

	i = 0;
	if(inst1 == END)
		re = malloc(sizeof(int) * 1);
	else if(inst2 == END)
	{
		re = malloc(sizeof(int) * 2);
		re[i++] = inst1;
	}
	else
	{
		re = malloc(sizeof(int) * 3);
		re[i++] = inst1;
		re[i++] = inst2;
	}
	re[i] = END;
	return(re);
}

int	*sort3B(t_list *list)
{
	int	comp01;
	int	comp02;
	int	comp12;
	int	*re;
	int	i;

	comp01 = comp01B(list);
	comp02 = comp02B(list);
	comp12 = comp12B(list);
	if(comp01 == NOSORTED && comp02 == NOSORTED && comp12 == NOSORTED)
		re = create2re(SB, RRB);
	else if(comp01 == NOSORTED && comp02 == NOSORTED)
		re = create2re(RB, END);
	else if(comp02 == NOSORTED && comp12 == NOSORTED)
		re = create2re(RRB, END);
	else if(comp01 == NOSORTED)
		re = create2re(SB, END);
	else if(comp12 == NOSORTED)
		re = create2re(SB, RB);
	else
		re = create2re(END, END);
	i = -1;
	while(re[++i] != END)
		do_inst_noput(list, re[i]);
	return(re);
}