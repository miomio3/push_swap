#include "push_swap.h"

int	put_error(void)
{
	ft_putstr("argument is invalid\n");
	return(ERROR);
}

int	arg_error(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	if(argc < 2)
		return(put_error());
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
			if(argv[i][j] > '9' || argv[i][j++] < '0')
				return(put_error());
		i++;
	}
	return(NOERROR);
}

int	main(int argc, char **argv)
{
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	return(0);
}