#include "push_swap.h"

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

int	select_smallerin4(rr, rrr, rrbra, rrarb)
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