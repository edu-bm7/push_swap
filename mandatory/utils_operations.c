#include "push_swap.h"

t_bool is_empty(int top)
{
	if (top == -1)
		return (true_);
	return (false_);
}

t_bool is_full(int top, size_t size)
{
	if (top == (int)size - 1)
		return (true_);
	return (false_);
}
