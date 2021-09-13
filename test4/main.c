#include "push_swap.h"


int	main()//int argc, char **argv)
{
	t_list	*list;
	int		*array;
	int		center;
	int		argc;
	char	*argv[5] = {"","1", "3","4","5"};
	t_list	*debug;
	int		intdebug;

	argc = 5; 
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	array = make_int(list, argc);
	bouble(array, argc, list);
	intdebug = isA_sorted_enst(list);
	//quick(list);
	//free_list(list);
}