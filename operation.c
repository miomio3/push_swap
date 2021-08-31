#include "push_swap.h"

void	op_rra(t_list *list, int len)
{
	int		i;
	t_list	*zero;

	zero = list;
	i = 0;
	while(i < len)
	{
		zero->order = i;
		zero = zero->next;
		i++;
	}
	ft_putstr("rra\n");
}