#include "push_swap.h"

void	init_stack(int **bottom_stack, int **top_stack, int argc)
{
	*bottom_stack = malloc(sizeof(int) * argc / 2);
	*top_stack = malloc(sizeof(int) * argc / 2);
	**(bottom_stack) = 0;
	**(top_stack) = argc - 2;
}

int	search_center(t_list *list, int pbottom, int ptop)
{
	int		x;
	int		bottom;
	int		top;
	t_list	*plist;

	plist = list;
	top = search_list(list, ptop)->num;
	bottom = search_list(list, pbottom)->num;
	x = search_list(list, (pbottom + ptop) / 2)->num;
	if((x >= top && top >= bottom) || (x <= top && top <= bottom))
		return(top);
	if((x >= bottom && bottom >= top) || (x <= bottom && bottom <= top))
		return(bottom);
	return(x);
}

void	init_p(int *bottom_stack, int *top_stack, int *ptop, int *pbottom, int p)
{
	*pbottom = bottom_stack[p];
	*ptop = top_stack[p];
}

void	quick(t_list *list, int argc)
{
	int	*bottom_stack;
	int	*top_stack;
	int	pbottom;
	int	ptop;
	int	bottom;
	int	top;
	int	p;
	int	x;

	if (malloc_error(&bottom_stack, &top_stack) == ERROR)
		return;
	init_stack(&bottom_stack, &top_stack, argc);
	p = 1;
	while(p-- > 0)
	{
		init_p(bottom_stack, top_stack, &ptop, &pbottom, p);
		init_p(bottom_stack, top_stack, &top, &bottom, p);
		search_swap(list, &ptop, &pbottom, &top, &bottom, search_center(list, pbottom, ptop));
		if(pbottom < top)
			push_stack(&bottom_stack, &top_stack, pbottom, top, p++);
		if(ptop > bottom)
			push_stack(&bottom_stack, &top_stack, bottom, ptop, p++);
	}
}
/* 
int main(void)
{
	t_list	*list;
	int		argc;

	argc = 11;
	char *data[11] = {"", "0", "234", "-1", "789", "567", "678", "888", "111", "-2147483648", "2147483647"};
	list = make_list(argc, data);
	quick(list, argc);
	while(--argc)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
	return(0);
} */