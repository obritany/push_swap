#include "push_swap.h"

typedef struct	s_stack
{
	int *nums;
	int len;
	int actlen;
}				t_stack;

// void print_nums(int *nums, int len)
// {
// 	int i;

// 	i = 0;
// 	while (i < len)
// 		printf("%d\n", nums[i++]);
// 	printf("\n");
// }

void print_rotate(int dir, int print)
{
	if (print == 1 && dir == 1)
		write(1, "rra\n", 4);
	if (print == 1 && dir == -1)
		write(1, "ra\n", 3);
	if (print == -1 && dir == 1)
		write(1, "rrb\n", 4);
	if (print == -1 && dir == -1)
		write(1, "rb\n", 3);
}

void rotate(int *nums, int len, int dir, int print)
{
	int i;
	int k;
	int start;
	int end;
	int temp[2];

	start = 0;
	end = len - 1;
	if (dir == -1)
	{
		start = len - 1;
		end = 0;
	}
	i = start;
	k = 0;
	temp[k] = nums[start];
	while (i != end)
	{
		temp[!k] = nums[i + dir];
		nums[i + dir] = temp[k];
		k = !k;
		i += dir;
	}
	nums[start] = temp[k];
	print_rotate(dir, print);
}

void swap(int *nums, int print)
{
	int temp;

	temp = (nums)[0];
	(nums)[0] = (nums)[1];
	(nums)[1] = temp;
	if (print == 1)
		write(1, "sa\n", 3);
	if (print == -1)
		write(1, "sb\n", 3);
}

int push(t_stack *src, t_stack *dest, int print)
{
	if (src->actlen == 0)
		return (1);
	dest->len++;
	dest->actlen++;
	rotate(dest->nums, dest->len, 1, 0);
	dest->nums[0] = src->nums[0];
	rotate(src->nums, src->len, -1, 0);
	src->len--;
	src->actlen--;
	if (print == 1)
		write(1, "pb\n", 3);
	if (print == -1)
		write(1, "pa\n", 3);
	return (0);
}

int sorted(int *nums, int len, int mode)
{
	int i;

	if (len < 2)
		return (mode);
	i = 0;
	while (nums[i] == nums[i + 1])
		i++;
	while (i < len - 1)
	{
		if ((mode == 1 && nums[i] > nums[i + 1]) ||
			(mode == -1 && nums[i] < nums[i + 1]))
			return (0);
		i++;
	}
	return (mode);
}

void sort_nums(int *nums, int len)
{
	int i;
	int k;

	i = 0;
	while (i < len - 1)
	{
		if (nums[i] > nums[i + 1])
		{
			k = i;
			while (i--)
				rotate(nums, len, -1, 0);
			swap(nums, 0);
			while (k--)
				rotate(nums, len, 1, 0);
		}
		i++;
	}
}

int find_next_num(int *nums, int len, int median, int mode)
{
	int i;
	int first;
	int last;

	i = 0;
	first = -1;
	last = -1;
	while (i < len)
	{
		if ((nums[i] < median && mode == 1) ||
			(nums[i] > median && mode == -1))
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

int split_median(t_stack *src, t_stack *dest, int mode)
{
	int i;
	int median;
	int dir;
	int *tnums;
	int tlen;
	
	if (src->actlen < 2)
		return (1);
	if (src->actlen < 4)
	{
		if ((src->nums[0] > src->nums[1] && mode == 1) ||
			(src->nums[0] < src->nums[1] && mode == -1))
			swap(src->nums, mode);
		if (src->actlen < 3)
			return (2);
	}
	tnums = malloc(sizeof(int) * src->actlen);
	tlen = src->actlen;
	ft_memcpy(tnums, src->nums, src->actlen * sizeof(int));
	sort_nums(tnums, tlen);
	median = tnums[tlen / 2];
	free(tnums);

	tlen = 0;
	i = 0;
	while (1)
	{
		if (sorted(src->nums, src->actlen, mode) &&
			tlen == 0 && src->len == src->actlen)
				return (3);
		dir = find_next_num(src->nums, src->len, median, mode);
		if (!dir)
			break ;
		if ((src->nums[0] < median && mode == 1) ||
	 		(src->nums[0] > median && mode == -1))
		{
			push(src, dest, mode);
			tlen++;
		}
		else
		{
			rotate(src->nums, src->len, dir, mode);
			i += dir;
		}
	}
	if (tlen == 0)
		return (4);
	if (i < 0 && src->len != src->actlen)
		while(i++ != 0)
			rotate(src->nums, src->len, 1, mode);
	if (!sorted(src->nums, src->actlen, mode))
		split_median(src, dest, mode);
	dest->actlen = tlen;
	split_median(dest, src, -mode);
	while (tlen--)
		push(dest, src, -mode);
	dest->actlen = dest->len;
	return (0);
}

int main(int argc, char *argv[])
{
	int i;
	t_stack a;
	t_stack b;

	if (argc == 1)
		return (0);

	a.nums = malloc(sizeof(int) * (argc - 1));
	b.nums = malloc(sizeof(int) * (argc - 1));

	a.len = argc - 1;
	b.len = 0;
	a.actlen = a.len;
	b.actlen = b.len;
	i = a.len;
	while (i-- > 0)
		a.nums[i] = ft_atoi(argv[i + 1]);

	split_median(&a, &b, 1);

	// printf("\nA:\n");
	// print_nums(a.nums, a.len);
	// printf("B:\n");
	// print_nums(b.nums, b.len);
	// write(1, "sa\n", 3);
	return (0);
}