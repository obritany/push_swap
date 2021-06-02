#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*nums;
	int	len;
	int	actlen;
}	t_stack;

int		push(t_stack *src, t_stack *dest, int print);
int		swap(int *nums, int print);
int		rotate(int *nums, int len, int dir, int print);

int		read_nums(char *argv[], int *nums, int len);
void	sort_nums(int *nums, int len);
int		sorted(int *nums, int len, int mode);

void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif