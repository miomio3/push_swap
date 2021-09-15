#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	int		*array;
	int		center;
	/* int		argc;
	char	*argv[8] = {"", "1","2", "4", "0", "3", "5"};
	t_list	*debug;
	int		intdebug;

	argc = 7; */
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	array = make_int(list, argc);
	bouble(array, argc, list);
	quick(list);
	free_list(list);
	return(0);
}

//-1704381943 -1361918211 182008694 -1954153013 -360864187 1576203921