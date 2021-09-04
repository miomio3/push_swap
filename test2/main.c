#include "push_swap.h"


int	put_error(void)
{
	ft_putstr("Errror\n");
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
	t_list	*list;
	int i;

	//char *argv[6] = {"", "1353271128", "-1941500750","-1627890091"};
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	insertion(list, argc);
	return(0);
}