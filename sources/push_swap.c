#include "push_swap.h"

int	next_num_dir(int *nums, int len, int median, int mode)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = -1;
	last = -1;
	while (i < len)
	{
		if ((nums[i] < median && mode == 1)
			|| (nums[i] > median && mode == -1))
		{
			if (first == -1)
				first = i;
			last = i;
		}
		i++;
	}
	if (first == -1)
		return (0);
	if (first < len - last)
		return (-1);
	return (1);
}

int	get_median(t_stack *stack)
{
	int	*tnums;
	int	tlen;
	int	median;

	tnums = malloc(sizeof(int) * stack->actlen);
	if (!tnums)
		exit (3);
	tlen = stack->actlen;
	ft_memcpy(tnums, stack->nums, stack->actlen * sizeof(int));
	sort_nums(tnums, tlen);
	median = tnums[tlen / 2];
	free(tnums);
	return (median);
}

int	split_median(t_stack *src, t_stack *dest, int mode, int median)
{
	int	pushlen;
	int	rotcount;
	int	dir;

	median = get_median(src);
	pushlen = 0;
	rotcount = 0;
	while (1)
	{
		if (sorted(src->nums, src->actlen, mode)
			&& pushlen == 0 && src->len == src->actlen)
			return (-3);
		dir = next_num_dir(src->nums, src->len, median, mode);
		if (!dir)
			break ;
		if ((src->nums[0] < median && mode == 1)
			|| (src->nums[0] > median && mode == -1))
			pushlen += push(src, dest, mode);
		else
			rotcount += rotate(src->nums, src->len, dir, mode);
	}
	if (rotcount < 0 && src->len != src->actlen)
		while (rotcount++ != 0)
			rotate(src->nums, src->len, 1, mode);
	return (pushlen);
}

int	quick_sort(t_stack *src, t_stack *dest, int mode)
{
	int	pushlen;

	if (src->actlen < 2)
		return (1);
	if (src->actlen < 4)
	{
		if ((src->nums[0] > src->nums[1] && mode == 1)
			|| (src->nums[0] < src->nums[1] && mode == -1))
			swap(src->nums, mode);
		if (src->actlen < 3)
			return (2);
	}
	pushlen = split_median(src, dest, mode, 0);
	if (pushlen <= 0)
		return (pushlen);
	if (!sorted(src->nums, src->actlen, mode))
		quick_sort(src, dest, mode);
	dest->actlen = pushlen;
	quick_sort(dest, src, -mode);
	while (pushlen--)
		push(dest, src, -mode);
	dest->actlen = dest->len;
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	a.nums = malloc(sizeof(int) * (argc - 1));
	b.nums = malloc(sizeof(int) * (argc - 1));
	if (!a.nums || !b.nums)
		return (2);
	a.len = argc - 1;
	b.len = 0;
	a.actlen = a.len;
	b.actlen = b.len;
	i = a.len;
	while (i-- > 0)
		a.nums[i] = ft_atoi(argv[i + 1]);
	quick_sort(&a, &b, 1);
	free(a.nums);
	free(b.nums);
	return (0);
}
