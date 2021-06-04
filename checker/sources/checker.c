/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:16:45 by obritany          #+#    #+#             */
/*   Updated: 2021/06/04 13:16:50 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_rotate(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("ra", cmd))
		rotate(a->nums, a->len, -1, 0);
	else if (!ft_strcmp("rb", cmd))
		rotate(b->nums, b->len, -1, 0);
	else if (!ft_strcmp("rr", cmd))
	{
		rotate(a->nums, a->len, -1, 0);
		rotate(b->nums, b->len, -1, 0);
	}
	else if (!ft_strcmp("rra", cmd))
		rotate(a->nums, a->len, 1, 0);
	else if (!ft_strcmp("rrb", cmd))
		rotate(b->nums, b->len, 1, 0);
	else if (!ft_strcmp("rrr", cmd))
	{
		rotate(a->nums, a->len, 1, 0);
		rotate(b->nums, b->len, 1, 0);
	}
	else
		return (1);
	return (0);
}

int	parse_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("sa", cmd))
		swap(a->nums);
	else if (!ft_strcmp("sb", cmd))
		swap(b->nums);
	else if (!ft_strcmp("ss", cmd))
	{
		swap(a->nums);
		swap(b->nums);
	}
	else if (!ft_strcmp("pa", cmd))
		push(b, a);
	else if (!ft_strcmp("pb", cmd))
		push(a, b);
	else if (!parse_rotate(cmd, a, b))
		return (0);
	else
		return (1);
	return (0);
}

int	read_cmds(t_stack *a, t_stack *b)
{
	int		len;
	char	ch;
	char	buffer[5];

	len = 0;
	while (read(0, &ch, 1) > 0)
	{
		buffer[len++] = ch;
		if (ch == '\n')
		{
			buffer[len - 1] = '\0';
			if (parse_cmd(buffer, a, b))
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
	if (read_nums(argv, a.nums, a.len) || read_cmds(&a, &b))
	{
		write(2, "Error\n", 6);
		return (3);
	}
	if (sorted(a.nums, a.len, 1) && b.len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.nums);
	free(b.nums);
	return (0);
}
