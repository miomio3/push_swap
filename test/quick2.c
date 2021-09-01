#include "push_swap.h"

int	malloc_error(int **bottom_stack, int **top_stack)
{
	if(*bottom_stack == NULL)
	{
		free(*top_stack);
		ft_putstr("malloc_error occurred\n");
		return(ERROR);
	}
	if(*top_stack == NULL)
	{
		free(*bottom_stack);
		ft_putstr("malloc_error occurred\n");
		return(ERROR);
	}
	return(NOERROR);
}

void	push_stack(int **bottom_stack, int **top_stack,  int bottom, int top, int p)
{
	bottom_stack[0][p] = bottom;
	top_stack[0][p] = top;
}

void	search_swap(t_list *list, int *ptop, int *pbottom, int *top, int *bottom, int center)
{
	t_list	*top_plist;
	t_list	*bottom_plist;

	top_plist = search_list(list, *top);
	bottom_plist = search_list(list, *bottom);
	while(*ptop > *pbottom)
	{
		while(top_plist->num > center)
			top_plist = search_list(list, --*ptop);
		while(bottom_plist->num < center)
			bottom_plist = search_list(list, ++*pbottom);
		if(*ptop >= *pbottom)
		{
			swap_data(top_plist, bottom_plist);
			--*ptop;
			++*pbottom;
		}
	}
}