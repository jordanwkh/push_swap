/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 15:45:40 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/06 21:38:07 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	nbr_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (!str[i])
			return (false);
	}
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	dup_check(int *nbrs, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nbrs[i] == nbrs[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	free_stack(t_stack *to_free)
{
	if (to_free->prev)
		to_free->prev->next = NULL;
	while (to_free->next != NULL)
	{
		to_free = to_free->next;
		free(to_free->prev);
		to_free->prev = NULL;
	}
	free(to_free);
	return ;
}

void	return_error(t_info *info, bool error)
{
	free(info->all_nbrs);
	free(info->copy);
	if (info->stack_a != NULL)
		free_stack(info->stack_a);
	if (info->stack_b != NULL)
		free_stack(info->stack_b);
	if (error)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	exit(0);
}

void	bubblesort(int *nbrs, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (j + 1 < argc)
		{
			if (nbrs[j] > nbrs[j + 1])
			{
				temp = nbrs[j];
				nbrs[j] = nbrs[j + 1];
				nbrs[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
