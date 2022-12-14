/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 14:43:32 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/09 15:07:30 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>

typedef struct info
{
	int	*all_nbrs;
	int	*copy;
}	t_info;

typedef struct stack
{
	int					nbrs;
	struct stack		*next;
	struct stack		*prev;
	struct stack		**stack_a;
}	t_stack;

bool	nbr_check(char *str);
bool	dup_check(int *nbrs, int count);
void	parsing(t_info *info, int argc, char **argv);
void	return_error(t_info *info, char *message);
void	bubblesort(int *nbrs, int argc);
bool	check_sort(t_stack *stack);
void	swapping(char c, t_stack *stack);
void	two_swaps(t_stack stack_a, t_stack stack_b);
void	rotate(char c, t_stack **stack);
void	duo_rotate(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(char c, t_stack **stack);
void	duo_rev_rotate(t_stack **stack_a, t_stack **stack_b);
#endif
