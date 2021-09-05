#include "push_swap.h"

int	absolute_value(int num)
{
	if(num < 0)
		num = num * (-1);
	return(num);
}

int	select_bigger(int num1, int num2)
{
	if(num1 > num2)
		return(num1);
	else
		return(num2);
}