#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define ERROR	-1
#define NOERROR	1
#define A		0
#define B		1

typedef	struct t_list
{
	int				num;
	int				a_b;
	int				order;
	struct t_list	*next;
	struct t_list	*prev;
}t_list;

int		put_error(void);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi_errorcheck(const char *str);
t_list	*make_list(int argc, char *argv[]);
int		ft_atoi(const char *str);
t_list	*search_lowest_in3(t_list *list);
void	sort_three(t_list *list, int argc);
void	swap(t_list *a, t_list *b);
void	op_rra(t_list *list, int argc);
void	swap_top2(t_list *zero, int order);
void	swap_data(t_list *a, t_list *b);
void	search_swap(t_list *list, int *ptop, int *pbottom, int *top, int *bottom, int center);
t_list	*search_list(t_list *list, int order);
void	push_stack(int **bottom_stack, int **top_stack,  int bottom, int top, int p);
int		malloc_error(int **bottom_stack, int **top_stack);
int		search_center(t_list *list, int pbottom, int ptop);

#endif