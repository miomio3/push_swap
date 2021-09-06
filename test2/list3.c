#include "push_swap.h"

void	delarray_fromlast(int *array, int max_array, int num)
{
	int	i;

	i = 0;
	while(array[max_array - i - 1] != num)
		i++;
	while(&array[max_array - i - 1] != &array[max_array])
	{
		array[max_array - i - 1] = array[max_array - i];
		i--;
	}
}

t_list	*search_pushnum_from0(t_list *list, int *array, int argc, int a_b, int times)
{
	t_list	*p;
	int		f;
	int		i;

	if(a_b == A)
		p = search_list(list, 0);
	else
		p = search_Blast(list);
	f = 1;
	while(f)
	{
		i = -1;
		while(++i < PUSH2B - times && f)
			if(p->num == array[argc - 2 - times - i] && f)
				f = 0;
		p = p->next;
	}
	return(p->prev);
}


t_list	*search_pushnum_fromlast(t_list *list, int *array, int argc, int a_b, int times)
{
	t_list	*p;
	int		i;
	int		f;

	if(a_b == A)
		p = search_Alast(list);
	else
		p = search_list(list, argc - 2);
	f = 1;
	while(f)
	{
		i = -1;
		while(++i < PUSH2B - times && f)
			if(p->num == array[argc - 2 - times - i] && f)
				f = 0;
		p = p->prev;
	}
	return(p->next);
}

t_list	*search_listnum_nosorted(t_list *list, int num, int a_b)
{
	int		i;
	t_list	*p;

	i = 0;
	if(a_b == A)
	{
		p = search_Alast(list);
		while(p->num != num || p->sorted != 0)
			p = p->prev;
	}
	else
	{
		p = search_Blast(list);
		while(p->num != num || p->sorted != 0)
			p = p->next;
	}
	return(p);
}
