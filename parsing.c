/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 16:51:43 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/06 21:03:36 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_nbrs(t_info *info, int size)
{
	int		i;
	int		*copy;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return_error(info, true);
	i = 0;
	while (i < size)
	{
		copy[i] = info->all_nbrs[i];
		i++;
	}
	return (copy);
}

static	void	value_nbrs( t_info *info, int argc)
{
	int	i;
	int	j;

	info->copy = copy_nbrs(info, argc - 1);
	bubblesort(info->copy, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (info->all_nbrs[i] == info->copy[j])
			{
				info->all_nbrs[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	free(info->copy);
	info->copy = NULL;
}

int	*parsing(t_info *info, int argc, char **argv)
{
	int		i;
	int		j;
	long	temp;

	info->all_nbrs = (int *)malloc(sizeof(int) * (argc - 1));
	if (!info->all_nbrs)
		return_error(info, true);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!nbr_check(argv[i]))
			return_error(info, true);
		temp = ft_atoi(argv[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return_error(info, true);
		info->all_nbrs[j] = temp;
		i++;
		j++;
	}
	if (!dup_check(info->all_nbrs, (argc - 1)))
		return_error(info, true);
	value_nbrs(info, argc);
	return (info->all_nbrs);
}
