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
#define PUSH2B	argc/2

typedef	struct t_list
{
	int				num;
	int				a_b;
	int				order;
	struct t_list	*next;
	struct t_list	*prev;
	int				last;
}t_list;

int		put_error(void);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi_errorcheck(const char *str);
t_list	*make_list(int argc, char **argv);
int		ft_atoi(const char *str);
void	bouble(int	*a, int argc);
void	ra_2push(t_list *list);
void	insertion(t_list *list, int argc);
void	rra(t_list *list);
void	ra(t_list *list);
void	pb(t_list *list);
void	pa(t_list *list);
t_list	*search_Alast(t_list	*list);
t_list	*search_Blast(t_list	*list);
t_list	*search_pushnum_from0(t_list *list, int *array, int argc, int a_b);
t_list	*search_pushnum_fromlast(t_list *list, int *array, int argc, int a_b);
t_list	*search_listnum(t_list *list, int num, int ab);
t_list	*search_list(t_list *list, int order);
void	swap_data(t_list *a, t_list *b);
int		is_sorted(t_list *list);
int		is_B(t_list *list);

#endif