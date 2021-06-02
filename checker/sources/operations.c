#include "checker.h"

int	rotate(int *nums, int len, int dir, int k)
{
	int	i;
	int	start;
	int	end;
	int	temp[2];

	if (len == 0)
		return (dir);
	start = 0;
	end = len - 1;
	if (dir == -1)
		start = len - 1;
	if (dir == -1)
		end = 0;
	i = start;
	temp[k] = nums[start];
	while (i != end)
	{
		temp[!k] = nums[i + dir];
		nums[i + dir] = temp[k];
		k = !k;
		i += dir;
	}
	nums[start] = temp[k];
	return (dir);
}

int	swap(int *nums)
{
	int	temp;

	temp = (nums)[0];
	(nums)[0] = (nums)[1];
	(nums)[1] = temp;
	return (0);
}

int	push(t_stack *src, t_stack *dest)
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
	return (1);
}
