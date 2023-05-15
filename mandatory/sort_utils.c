#include "push_swap.h"

int	find_min(const int *arr, int top)
{
	int min;

	min = arr[top];
	while (top != -1)
	{
		if (arr[top] < min)
			min = arr[top];
		top--;
	}
	return (min);
}

int	find_max(const int *arr, int top)
{
	int max;

	max = arr[top];
	while (top != -1)
	{
		if (arr[top] > max)
			max = arr[top];
		top--;
	}
	return (max);
}

t_bool	is_sorted(const int *arr, int top)
{
	while (top)
	{
		if (arr[top] > arr[top - 1])
			return (false_);
		top--;
	}
	return (true_);
}

size_t	find_index(const int *arr, int value, int top)
{
	int i;

	i = 0;
	while (i < top)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (i);
}
