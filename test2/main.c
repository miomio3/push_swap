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

	char *argv[5] = {"", "11", "1", "-1", "11"};
	if(arg_error(5, argv) == ERROR)
		return(ERROR);
	list = make_list(5, argv);
	insertion(list, 5);
	return(0);
}