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
t_list	*make_list(int argc, char argv[3][4]);
int		ft_atoi(const char *str);

#endif