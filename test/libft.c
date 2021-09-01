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


static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
	c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static int	ft_overflow(unsigned long nb, char str, int sign)
{
	if (sign == 1)
	{
		if ((nb == (unsigned long)LONG_MAX / 10 && \
		str - '0' >= (int)LONG_MAX % 10 ) || \
		nb > (unsigned long)LONG_MAX / 10)
			return (1);
	}
	else
	{
		if ((nb == (unsigned long)LONG_MIN / 10 && \
		str - '0' >= (int)LONG_MIN % 10) || \
		nb > (unsigned long)LONG_MIN / 10)
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	int			nb;
	int			overflow;

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
		overflow = ft_overflow(nb, str[i], sign);
		if (overflow == -1)
			return ((int)LONG_MIN);
		if (overflow == 1)
			return ((int)LONG_MAX);
		nb = nb * 10 + (str[i++] - '0');
	}
	return ((int)nb * sign);
}