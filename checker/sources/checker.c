#include "checker.h"

int read_cmds()
{
	int		len;
	char	ch;
	char	buffer[5];

	while(read(0, &ch, 1) > 0)
	{
		buffer[len++] = ch;
		if (ch == '\n')
		{
			buffer[len - 1] = '\0';
			if (!ft_strcmp("sa", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("sb", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("ss", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("pa", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("pb", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("ra", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("rb", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("rr", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("rra", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("rrb", buffer))
				write(1, "OK\n", 3);
			else if (!ft_strcmp("rrr", buffer))
				write(1, "OK\n", 3);
			else
				return (1);
			len = 0;
		}
		if (len > 3)
			return (2);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
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
	if (read_nums(argv, a.nums, a.len) || read_cmds())
	{
		write(2, "Error\n", 6);
		free(a.nums);
		free(b.nums);
		return (3);
	}
	free(a.nums);
	free(b.nums);
	return (0);
}