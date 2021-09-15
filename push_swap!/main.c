#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	int		*array;
	int		center;
	/* int		argc;
	char	*argv[8] = {"", "4","3", "1", "2", "0"};
	t_list	*debug;
	int		intdebug;

	argc = 6; */
	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	array = make_int(list, argc);
	bouble(array, argc, list);
	quick(list);
	free_list(list);
	return(0);
}

//-452855385 -537315133 -788512405 -623367599 -1552496856