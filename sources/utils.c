#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long long	pre_max;
	unsigned long long	rslt;
	int					sign;
	int					i;

	pre_max = 922337203685477580;
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
				return (-1);
		if (sign == -1)
			if (rslt > pre_max || (rslt == pre_max && str[i] > '8'))
				return (0);
		rslt = (rslt * 10) + (str[i++] - '0');
	}
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