#include "push_swap.h"

int	*ft_intstrjoin(int *a, int *b)
{
	int	i;
	int	j;
	int	lenA;
	int	lenB;
	int	*re;

	lenA = ft_intstrlen(a);
	lenB = ft_intstrlen(b);
	re = malloc(sizeof(int) * (lenA + lenB + 1));
	ft_intstrcpy(re, a);
	ft_intstrcpy(&re[lenA], b);
	if(a != NULL)
		safe_free(a);
	if(b != NULL)
		safe_free(b);
	return(re);
}
