/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 14:43:32 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:26:32 by jhoekstr      ########   odam.nl         */
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
}	t_stack;

bool	nbr_check(char *str);
bool	dup_check(int *nbrs, int count);
void	parsing(t_info *info, int argc, char **argv);
void	return_error(t_info *info, char *message);
void	bubblesort(int *nbrs, int argc);
#endif
