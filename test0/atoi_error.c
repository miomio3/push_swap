#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
	c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi_errorcheck(const char *str)
{
	size_t		i;
	int			sign;
	int			nb;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if(((nb  * 10 * sign + (str[i] - '0') * sign) / 10) != nb * sign)
			return(ERROR);
		nb = nb * 10 + (str[i++] - '0');
	}
	return (NOERROR);
}
