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
}

void	swap_top2(t_list *list, int order)
{
	t_list	*zero;
	t_list	*tmplist;

	zero = list;
	tmplist = malloc(sizeof(t_list) * 1);
	while(zero->order != order)
		zero = zero->next;
	if(zero->num < zero->prev->num)
	{
		swap_data(zero, zero->prev);
		ft_putstr("sa\n");
	}
}

void	swap(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}