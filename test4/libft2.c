#include "push_swap.h"

int	select_bigger_num(int num1, int num2)
{
	if(num1 < num2)
		return(num2);
	else
		return(num1);
}

void	safe_free(int *array)
{
	if(array != NULL)
		free(array);
	array = NULL;
}

void	copy2re(int *re, int *tmp, int *tmp1)
{
	tmp = ft_intstrjoin(tmp1, re);
	safe_free(tmp1);
	safe_free(re);
	ft_intstrcpy(re, tmp);
	safe_free(tmp);
}

int	ft_intstrlen(int *a)
{
	int	i;

	if(a == NULL)
		return(0);
	i = 0;
	while(a[i] != END)
		i++;
	return(i);
}

void	ft_intstrcpy(int *a, int *b)
{
	int	i;

	i = 0;
	if(b == NULL)
	{
		a[i] = END;
		return;
	}
	while(b[i] != END)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = END;
}
