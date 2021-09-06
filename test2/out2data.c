#include "push_swap.h"

void	assign_out2(out2 *out, int instruction, t_list *a, t_list *b)
{
	out->instruction = instruction;
	out->pa = a;
	out->pb = b;
}