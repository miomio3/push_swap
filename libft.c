#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}