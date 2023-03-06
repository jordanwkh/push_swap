/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 15:45:40 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/03/02 20:41:43 by jhoekstr      ########   odam.nl         */
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

void	return_error(t_info *info)
{
	free(info->all_nbrs);
	ft_putendl_fd("Error", 2);
	exit(1);
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
