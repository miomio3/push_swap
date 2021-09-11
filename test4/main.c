#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	//sort(list);
	free_list(list);
}