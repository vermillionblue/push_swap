#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"

int *placenums(int argc, char **argv);
void	push_ab(int	*stack_a, int *stack_b, int *argc, int *argb);
int	senderror(char **argv);
int ft_checkdup(char **arr);
int	issmallest(int num, int *arr, int argc);
int	isbiggest(int num, int *arr, int argc);
int issorted(int *arr, int argc);
void rotate_r(int *arr, char c, int argc);
void ft_rotate(int *arr, char c, int argc);
void ft_swap(int *arr, char c);
void ft_swapab(int *arr1, int *arr2);
long int	ft_atol(const char *str);
int	*findchunks(int *stack_c,int *argc,  int *argb);

//////////REMOVE
void printarr(int argc, int	*arr);

#endif