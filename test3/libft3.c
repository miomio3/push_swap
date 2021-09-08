#include "push_swap.h"

int	*ft_intstrdup(int *array, int argc)
{
	int	*array2;
	int	i;

	array2 = malloc(sizeof(int) * argc - 1);
	i = -1;
	while(++i < argc - 1)
		array2[i] = array[i];
	return(array2);
}

int	select_bigger(int num1, int num2)
{
	if(num1 > num2)
		return(num1);
	else
		return(num2);
}

int	select_smaller(int num1, int num2)
{
	if(num1 < num2)
		return(num1);
	else
		return(num2);
}

int	select_smallerin4(int rr, int rrr, int rrbra, int rrarb)
{
	int	re;

	re = rr;
	if(re > rrr)
		re = rrr;
	if(re > rrbra)
		re = rrbra;
	if(re > rrarb)
		re = rrarb;
	return(re);
}



