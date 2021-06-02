#include "push_swap.h"

int	print_rotate(int dir, int print)
{
	if (print == 1 && dir == 1)
		write(1, "rra\n", 4);
	if (print == 1 && dir == -1)
		write(1, "ra\n", 3);
	if (print == -1 && dir == 1)
		write(1, "rrb\n", 4);
	if (print == -1 && dir == -1)
		write(1, "rb\n", 3);
	return (dir);
}

int	rotate(int *nums, int len, int dir, int print)
{
	int	i;
	int	k;
	int	start;
	int	end;
	int	temp[2];

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
	return (print_rotate(dir, print));
}

int	swap(int *nums, int print)
{
	int	temp;

	temp = (nums)[0];
	(nums)[0] = (nums)[1];
	(nums)[1] = temp;
	if (print == 1)
		write(1, "sa\n", 3);
	if (print == -1)
		write(1, "sb\n", 3);
	return (0);
}

int	push(t_stack *src, t_stack *dest, int print)
{
	if (src->actlen == 0)
		return (-1);
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
	return (1);
}
