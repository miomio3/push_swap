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
#define SORTED			1
#define NOSORTED		0
#define EXIST			1
#define NOEXIST			0

typedef	struct t_list
{
	int				arrayorder;
	int				sorted;
	int				num;
	int				a_b;
	int				order;//変えない
	struct t_list	*next;//変えない
	struct t_list	*prev;//変えない
	int				last;//変えない
}t_list;

typedef struct out2
{
	t_list *pa;
	t_list *pb;
	int		instruction;
}out2;

int		put_error(void);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi_errorcheck(const char *str);
int		select_smallerin4(int rr, int rrr, int rrbra, int rrarb);
t_list	*make_list(int argc, char **argv);
int		ft_atoi(const char *str);
void	bouble(int	*a, int argc, t_list *list);
int		ra2top_times(t_list *pa);
int		rra2top_times(t_list *pa);
int		rb2top_times(t_list *pb);
int		rrb2top_times(t_list *pb);
void	ra(t_list *list, int put);
void	rb(t_list *list, int put);
void	rr(t_list *list);
void	rra(t_list *list, int put);
void	rrb(t_list *list, int put);
void	rrr(t_list *list);
void	sa(t_list *list, int put);
void	sb(t_list *list, int put);
void	ss(t_list *list);
void	ss_rr(t_list *list);
void	sa_ra(t_list *list);
void	sb_rb(t_list *list);
void	rra_sa(t_list *list);
void	rrb_sb(t_list *list);
void	rrr_ss(t_list *list);
t_list	*search_Alast(t_list	*list);
t_list	*search_Blast(t_list	*list);
t_list	*search_last(t_list *list);
t_list	*search_first(t_list *list, int a_b);
t_list	*search_next(t_list *p, int a_b);
t_list	*search_prev(t_list *p, int a_b);
t_list	*search_list(t_list *list, int order);
t_list	*search_arrayorder(t_list *list, int j);
void	swap_data(t_list *a, t_list *b);
void	assign_nextdata(t_list *p);
void	assign_prevdata(t_list *p);
void	assign_data(t_list *p, int num, int sorted, int arrayorder);
void	assign_out2(out2 *out, int instruction, t_list *a, t_list *b);
int		is_sorted(t_list *list);
int		is_sortedAB(t_list *p, int a_b);
int		is_B(t_list *list);

#endif