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
	t_list	*list;

	if(arg_error(argc, argv) == ERROR)
		return(ERROR);
	list = make_list(argc, argv);
	sort_three(list, argc);
	/* printf("order = %d\n", list->order);//debug
	printf("num = %d\n", list->num);//debug
	printf("order = %d\n", list->next->order);//debug
	printf("num = %d\n", list->next->num);//debug
	printf("order = %d\n", list->next->next->order);//debug
	printf("num = %d\n", list->next->next->num);//debug */
	return(0);
}
//bash → ARG = <変数>; ./push_swap $ARG | ./checker_MAC　$ARG
//ARG = <変数>; ./push_swap $ARG | wc -l
//ARG = `jot -r -s " " 100 INT_MIN INT_MAX` //INT_MINからINT_MAXまでの乱数を100個、ARGに代入する