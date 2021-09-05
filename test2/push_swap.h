#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define ERROR			-1
#define NOERROR			1
#define A				0
#define B				1
#define PUSH2B			argc/2
#define NOINSTRUCTION	0
#define RRARB			1
#define RRBRA			2
#define RR				3
#define RRR				4
#define NOPUT			0
#define PUT				1

typedef	struct t_list
{
	int				num;
	int				a_b;
	int				order;//変えない
	struct t_list	*next;
	struct t_list	*prev;
	int				last;//変えない
	int				sorted;
}t_list;

int		put_error(void);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi_errorcheck(const char *str);
int		absolute_value(int num);
int		select_bigger(int num1, int num2);
t_list	*make_list(int argc, char **argv);
int		ft_atoi(const char *str);
void	bouble(int	*a, int argc);
void	ra_2push(t_list *list);
void	insertion(t_list *list, int argc);
void	ra(t_list *list, int put);
void	rb(t_list *list, int put);
void	rr(t_list *list);
void	rra(t_list *list, int put);
void	rrb(t_list *list, int put);
void	rrr(t_list *list);
void	pb(t_list *list);
void	pa(t_list *list);
void	rrbra2top(t_list *pa, t_list *pb, int Alast, int Blast);
void	rrarb2top(t_list *pa, t_list *pb, int Alast, int Blast);
void	instrution2top(int instration, t_list *pa, t_list *pb, int Alast, int Blast);
t_list	*search_Alast(t_list	*list);
t_list	*search_Blast(t_list	*list);
t_list	*search_pushnum_from0(t_list *list, int *array, int argc, int a_b);
t_list	*search_pushnum_fromlast(t_list *list, int *array, int argc, int a_b);
t_list	*search_listnum(t_list *list, int num, int ab);
t_list	*search_listnum_nosorted(t_list *list, int num);
t_list	*search_list(t_list *list, int order);
t_list	*search_last(t_list *list);
void	assign_nextdata(t_list *p);
void	assign_prevdata(t_list *p);
void	assign_data(t_list *p, int num, int sorted);
void	swap_data(t_list *a, t_list *b);
void	sort2(t_list *list, int *array, int argc);
int		next_instration2top(t_list *pa, t_list *pb, int Alast, int Blast);
int		is_sorted(t_list *list);
int		is_B(t_list *list);

#endif