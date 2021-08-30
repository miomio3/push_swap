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
		if(ft_atoi_errorcheck(argv[i]) == ERROR)
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
//ARG = <変数>; ./push_swap $ARG | ./checker_MAC
//ARG = `jot -r -s " " 100 INT_MIN INT_MAX` //INT_MINからINT_MAXまでの乱数を100個、ARGに代入する