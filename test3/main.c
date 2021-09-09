#include "push_swap.h"

int	put_error(void)
{
	ft_putstr("Error\n");
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

int	main(int argc, char **argv)
{
	t_list	*list;

	//char *argv[] = {"", "11" ,"-1", "1", "1", "-1", "1", "1", "20"};
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	sort(list, argc);
	free_list(list);
	return(0);
}

//"","11", "11", "11", "11" ,"-1"," 10" ,"1", "11" ,"11" ,"1", "1","1" ,"10","0" ,"0","-1" ,"1" ,"1" 　19個
//"", "11" ,"22", "0", "11", "0" ,"22" ,"1" ,"1" ,"0" ,"2" ,"0" ,"1" ,"0"