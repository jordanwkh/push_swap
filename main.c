/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 14:59:37 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/06 21:35:25 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		*nbrs;
	int		nbr_count;

	info.all_nbrs = NULL;
	info.copy = NULL;
	info.stack_a = NULL;
	info.stack_b = NULL;
	if (argc < 2)
		return_error(&info, false);
	nbr_count = argc - 1;
	nbrs = parsing(&info, argc, argv);
	info.stack_a = start_list(&info, nbrs, nbr_count);
	if (check_sort(info.stack_a))
		return_error(&info, false);
	sorting_all(&(info.stack_a), &(info.stack_b), nbr_count);
	return_error(&info, false);
}
