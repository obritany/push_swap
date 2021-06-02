#include "push_swap.h"

long	ft_atoi_smart(const char *str, unsigned long pre_max)
{
	unsigned long long	rslt;
	int					sign;
	int					i;

	rslt = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1)
			if (rslt > pre_max || (rslt == pre_max && str[i] > '7'))
				return (3000000000);
		if (sign == -1)
			if (rslt > pre_max || (rslt == pre_max && str[i] > '8'))
				return (3000000000);
		rslt = (rslt * 10) + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (3000000000);
	return (rslt * sign);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*mydst;

	if (!dst && !src && n > 0)
		return (0);
	mydst = dst;
	while (n--)
	{
		*mydst = *(char *)src;
		mydst++;
		src++;
	}
	return (dst);
}

int	sorted(int *nums, int len, int mode)
{
	int	i;

	if (len < 2)
		return (mode);
	i = 0;
	while (nums[i] == nums[i + 1])
		i++;
	while (i < len - 1)
	{
		if ((mode == 1 && nums[i] > nums[i + 1])
			|| (mode == -1 && nums[i] < nums[i + 1]))
			return (0);
		i++;
	}
	return (mode);
}

void	sort_nums(int *nums, int len)
{
	int	i;
	int	k;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		k = 0;
		while (k < len - i - 1)
		{
			if (nums[k] > nums[k + 1])
			{
				temp = nums[k + 1];
				nums[k + 1] = nums[k];
				nums[k] = temp;
			}
			k++;
		}
		i++;
	}
}

int	read_nums(char *argv[], int *nums, int len)
{
	long	temp;
	int		i;
	int		k;

	i = 0;
	while (i < len)
	{
		temp = ft_atoi_smart(argv[i + 1], 214748364);
		if (temp == 3000000000)
			return (1);
		k = 0;
		while (k < i)
			if (nums[k++] == temp)
				return (2);
		nums[i] = temp;
		i++;
	}
	return (0);
}
