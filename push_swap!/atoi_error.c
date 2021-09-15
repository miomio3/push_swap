#include "push_swap.h"

int	put_error(void)
{
	ft_putstr("Error\n");
	return(ERROR);
}

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
	while (ft_isspace(str[i]) && i == 0)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	nb = 0;
	if(str[i] < '0' || str[i] > '9')
		return(ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if(((nb  * 10 * sign + (str[i] - '0') * sign) / 10) != nb * sign)
			return(ERROR);
		nb = nb * 10 + (str[i++] - '0');
	}
	return (NOERROR);
}

int	arg_error(int argc, char **argv)
{
	int	i;
	int	j;

	if(argc < 2)
		return(put_error());
	i = 1;
	while(i < argc)
	{
		j = 0;
		if(ft_atoi_errorcheck(argv[i]) == ERROR)
			return(put_error());
		i++;
	}
	return(NOERROR);
}
