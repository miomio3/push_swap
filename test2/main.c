#include "push_swap.h"


int	put_error(void)
{
	ft_putstr("Err*or\n");
	return(ERROR);
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

int	main()//int argc, char **argv)
{
	t_list	*list;

	char *argv[6] = {"", "1", "-1941500750","-1627890091", "111", "-1"};
	if(arg_error(6, argv) == ERROR)
		return(ERROR);
	list = make_list(6, argv);
	insertion(list, 6);
	return(0);
}