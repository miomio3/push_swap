#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR	-1
#define NOERROR	1

int		put_error(void);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);

typedef	struct t_list
{
	int				num;
	int				a_b;
	int				order;
	struct t_list	next;
	struct t_list	prev;
}t_list;

#endif