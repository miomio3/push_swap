#include "push_swap.h"

t_list	*searchA_smallest_nosorted(t_list *list)
{
	t_list	*p;
	t_list	*re;
	t_list	*next;

	p = searchA_start(list);
	re = p;
	while(p->enst != END)
	{
		next = search_next(p, A);
		if(re->sorted == SORTED)
			re = p;
		else if(re->arrayorder < p->arrayorder && p->sorted == NOSORTED)
			re = p;
		p = next;
	}
}

int	isA_sorted_enst(t_list *list)
{
	t_list	*p;
	t_list	*next;

	p = searchA_start(list);
	while(p->enst != END)
	{
		next = search_next(p, A);
		if(p->arrayorder > next->arrayorder)
			return(NOSORTED);
	}
	return(SORTED);
}

int	*next2topA(t_list *list, int put)
{
	t_list	*last;
	int		i;
	int		times;
	int		*array;

	last = searchA_last(list);
	times = last->order - list->order - 1;
	array = malloc(sizeof(int) * i * 2);
	array[times * 2 - 1] = END;
	i = 0;
	while(i < times)
	{
		sa(list, put);
		array[i * 2] = SA;
		if(i != 0)
		{
			ra(list, put);
			array[i * 2 + 1] = RA;
		}
		i++;
	}
	return(array);
}

int	*sa2sort(t_list *p, int put)
{
	int		*inst1;
	int		*inst2;
	t_list	*smallest_sorted;
	int		*re;

	inst1 = ra2top(p, NOPUT);
	smallest_sorted = searchA_smallest_sorted(p);//途中
	inst2 = next2topA(smallest_sorted, NOPUT);
	re = ft_intstrjoin(inst1, inst2);
	free(inst1);
	free(inst2);
	return(re);
}

int	*sortA(t_list *list)
{
	t_list	*p;
	int		i;
	int		*tmp;
	int		*tmp1;
	int		*re;

	if(isA_sorted_enst(list) == SORTED)
		return(NULL);
	i = 0;
	re = NULL;
	while(isA_sorted_enst(list) == NOSORTED)
	{
		p = searchA_smallest_nosorted(list);
		if(i == 0)
			p->sorted = SORTED;
		else
			tmp1 = sa2sort(p, NOPUT);
		tmp = ft_intstrjoin(tmp1, re);
		free(tmp1);
		free(re);
		re = tmp;
	}
}

