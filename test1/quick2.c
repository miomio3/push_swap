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

static void	swap2(t_list **top_plist, t_list **bottom_plist, int *ptop, int *pbottom)
{
	if((*top_plist)->num <= (*bottom_plist)->num)
		swap_data(*top_plist, *bottom_plist);
	*top_plist = (*top_plist)->prev;
	*bottom_plist = (*bottom_plist)->next;
	(*ptop)--;
	(*pbottom)++;
}

void	search_swap(t_list *list, int *ptop, int *pbottom, int *top, int *bottom, int center)
{
	t_list	*top_plist;
	t_list	*bottom_plist;

	top_plist = search_list(list, *top);
	bottom_plist = search_list(list, *bottom);
	if(*ptop - *pbottom == 1)
		swap2(&top_plist, &bottom_plist, ptop, pbottom);
	while(*ptop > *pbottom)
	{
		while(top_plist->num >= center)
			top_plist = search_list(list, --*ptop);
		while(bottom_plist->num <= center)
			bottom_plist = search_list(list, ++*pbottom);
		if(*ptop >= *pbottom)	
			swap2(&top_plist, &bottom_plist, ptop, pbottom);
	}
}