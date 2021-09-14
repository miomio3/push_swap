#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OVER			1
#define	UNDER			-1
#define FIXED			1
#define NOFIXED			0
#define ERROR			-1
#define NOERROR			1
#define A				0
#define B				1
#define PUSH2B			argc/2
#define NOINSTRUCTION	0
#define CONTINUE		1
#define NOTHING			-1
#define END				0
#define START			1
#define FIRST			1
#define RA				2
#define RRA				3
#define SA				4
#define PB				5
#define RB				6
#define RRB				7
#define SB				8
#define PA				9
#define RR				10
#define RRR				11
#define SS				12
#define PP				13
#define CREATE2			11
#define NOPUT			0
#define PUT				1
#define SORTED			1
#define NOSORTED		0
#define NOMORE			-1
#define EXIST			1
#define NOEXIST			0

typedef	struct t_list
{
	int				arrayorder;
	int				sorted;
	int				enst;//変える。pushされたら更新。
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

typedef struct tree_node
{
	int	moves;
	int	op;
	int	fixed;
	int remaining_array1;
	int	remaining_array2;
	struct tree_node *left;
	struct tree_node *center;
	struct tree_node *right;
	struct tree_node *prev;
}tree_node;

//dijk
int			cost(tree_node *tree);
int			count_array(int *array);
int			count_remaining_array1(tree_node *tree, int inst);
int			count_remaining_array2(tree_node *tree, int inst);
int			cost(tree_node *tree);
tree_node	*select_min_node(tree_node *right, tree_node *center, tree_node *left);
tree_node	*init_node(int *array1, int *array2);
tree_node	*search_min(tree_node *tree);
int			judge_next(int array1, int array2);
int			create_next(tree_node *min, int inst, int array1_inst, int array2_inst);
int			create_only2(tree_node *min, int array1_inst, int array2_inst);
tree_node	*create_node(tree_node *tree, int inst);
int			create_double(tree_node *min, int inst, int array1_inst, int array2_inst);
int			is_remaining_array(tree_node *tree);
int			*make_min_array(tree_node *min);
void		free_tree(tree_node *tree);
tree_node	*select_min_in2(tree_node *node1, tree_node *node2);

//libft
int			put_error(void);
void		ft_putstr(char *s);
size_t		ft_strlen(char *s);
int			ft_atoi(const char *str);
int			select_bigger_num(int num1, int num2);
int			*ft_intstrjoin(int *a, int *b);
void		safe_free(int *array);
void		ft_intstrcpy(int *a, int *b);
int			ft_intstrlen(int *a);
//atoi_error
int			ft_atoi_errorcheck(const char *str);
int			select_smallerin4(int rr, int rrr, int rrbra, int rrarb);
int			arg_error(int argc, char **argv);
int			put_error(void);
//list
t_list		*make_list(int argc, char **argv);
int			smallest_distance2topB(t_list *list);
int			enstAlen(t_list *list);
//bouble
void		bouble(int	*a, int argc, t_list *list);
//inst
void		ra(t_list *list, int put);
void		rb(t_list *list, int put);
void		rr(t_list *list, int put);
void		rra(t_list *list, int put);
void		rrb(t_list *list, int put);
void		rrr(t_list *list, int put);
void		sa(t_list *list, int put);
void		sb(t_list *list, int put);
void		ss(t_list *list, int put);
void		pb(t_list *list, int put);
void		pa(t_list *list, int put);
void		ss_rr(t_list *list);
void		sa_ra(t_list *list);
void		sb_rb(t_list *list);
void		rra_sa(t_list *list);
void		rrb_sb(t_list *list);
void		rrr_ss(t_list *list);
//inst2top
int			*ra2top(t_list *list, int put);
int			*rra2top(t_list *list, int put);
int			*rb2top(t_list	*list, int put);
int			*rrb2top(t_list *list, int put);
int			ra2top_times(t_list *pa);
int			rra2top_times(t_list *pa);
int			rb2top_times(t_list *pb);
int			rrb2top_times(t_list *pb);
//is
int			isA_over3(t_list *list);
int			isB_over3(t_list *list);
int			isA_sorted_enst(t_list *list);
//list_count
int			countA(t_list *list);
//search_arrayorder
int			centerA_arrayorder(t_list *list);
int			centerB_arrayorder(t_list *list);
//search_enst
t_list		*searchA_start(t_list *list);
t_list		*searchA_end(t_list *list);
t_list		*searchB_start(t_list *list);
t_list		*searchB_end(t_list *list);
//search_list
t_list		*searchA_last(t_list	*list);
t_list		*searchB_first(t_list	*list);
t_list		*search_last(t_list *list);
t_list		*search_first(t_list *list, int a_b);
t_list		*search_next(t_list *p, int a_b);
t_list		*search_prev(t_list *p, int a_b);
t_list		*search_list(t_list *list, int order);
t_list		*search_arrayorder(t_list *list, int j);
t_list		*search_nosorted_fromfirst(t_list *list, int a_b);
t_list		*search_nosorted_fromlast(t_list *list, int a_b);
//listdata
void		swap_data(t_list *a, t_list *b);
void		assign_nextdata(t_list *p);
void		assign_prevdata(t_list *p);
void		assign_data(t_list *p, t_list data);
void		assign_out2(out2 *out, int instruction, t_list *a, t_list *b);
int			is_sorted(t_list *list);
int			is_sortedAB(t_list *p, int a_b);
int			is_B(t_list *list);
//put_do_inst
void		put_inst(int *instA, int *instB);
void		do_inst_noput(t_list *list,int inst);
//push2a
void		push2a_biggercenter(t_list *list);
//push2b
void		push2b_undercenter(t_list *list);
//quick
void		quick(t_list *list);
int			is_over5_inA(t_list *list);
//sort
int			*make_int(t_list *list, int argc);
void		sort_both(t_list *list);
//sortB
int			*sort3B(t_list *list);
int			*sort2B(t_list *list);
int			*sortB(t_list *list);
//sortA
int			*sortA(t_list *list);
int			*sort2A(t_list *list);
//searchA_arrayorder
t_list		*searchA_smallest_arrayorder(t_list *list);
t_list		*searchA_biggest_arrayorder(t_list *list);

#endif