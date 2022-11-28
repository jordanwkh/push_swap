/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 15:45:40 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/11/28 18:12:16 by jhoekstr      ########   odam.nl         */
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

void	return_error(t_info *info, char *message)
{
	free(info->all_nbrs);
	ft_printf("%s\n", message);
	exit(1);
}

static int	*copy_nbrs(t_info *info, int size)
{
	int		i;
	int		*copy;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return_error(info, "Malloc failed.");
	i = 0;
	while (i < size)
	{
		copy[i] = info->all_nbrs[i];
		i++;
	}
	return (copy);
}

void	bubblesort(int *nbrs, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < (argc - 1))
	{
		while (j + 1 < (argc - 1))
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

static void value_nbrs( t_info *info, int argc)
{
	int	i;
	int	j;

	info->copy = copy_nbrs(info, argc - 1);
	bubblesort(info->copy, argc - 1);
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (info->all_nbrs[i] == info->copy[j])
			{
				info->all_nbrs[i] = j;
				break ;
			}
			j++;
		}

		i++;
	}

}

void	parsing(t_info *info, int argc, char **argv)
{
	int		i;
	int		j;

	info->all_nbrs = NULL;
	if (argc < 2)
		return_error(info, "Not enough arguments.");
	info->all_nbrs = (int *)malloc(sizeof(int) * (argc - 1));
	if (!info->all_nbrs)
		return_error(info, "Malloc failed. Oops.");
	i = 1;
	while (i < argc)
	{
		if (!nbr_check(argv[i]))
			return_error(info, "Not a number.");
		info->all_nbrs[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!dup_check(info->all_nbrs, (argc - 1)))
		return_error(info, "Found a sussy dupe.");
	value_nbrs(info, argc);
	j = 0;
	while (info->all_nbrs[j])
	{	
		ft_printf("%s\n", info->all_nbrs);
		j++;
	}

}
