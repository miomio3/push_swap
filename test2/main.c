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

	char *argv[8] = {"", "1", "-1941500750","-1627890091", "111", "-1", "11", "1"};
	if(arg_error(8, argv) == ERROR)
		return(ERROR);
	list = make_list(8, argv);
	insertion(list, 8);
	return(0);
}