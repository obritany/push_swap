#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*nums;
	int	len;
	int	actlen;
}	t_stack;

int		push(t_stack *src, t_stack *dest);
int		swap(int *nums);
int		rotate(int *nums, int len, int dir, int k);

int		read_nums(char *argv[], int *nums, int len);
int		sorted(int *nums, int len, int mode);
int		ft_strcmp(const char *s1, const char *s2);

#endif