#include "push_swap.h"

static void	swap_arrayorder(t_list *list, int j)
{
	t_list	*p1;
	t_list	*p2;

	p1 = search_arrayorder(list, j);
	p2 = search_arrayorder(list, j + 1);
	p1->arrayorder = j + 1;
	p2->arrayorder = j;
}

void	bouble(int	*a, int argc, t_list *list)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while(i < argc - 2)
	{
		j = 0;
		while(j < argc - 2)
		{
			if(a[j] < a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				swap_arrayorder(list, j);
			}
			j++;
		}
		i++;
	}
}

int	*make_int(t_list *list, int argc)
{
	int		i;
	int		*array;
	t_list	*p;

	array = malloc(sizeof(int) * argc - 1);
	p = list;
	i = 0;
	while(i < argc - 1)
	{
		array[i] = p->num;
		p->arrayorder = i;
		p = p->next;
		i++;
	}
	return(array);
}