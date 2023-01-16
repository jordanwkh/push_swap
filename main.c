/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 14:59:37 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/11 16:47:14 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_stack	*stack_a;
	int		*nbrs;
	int		nbr_count;

	nbr_count = argc - 1;
	nbrs = parsing(&info, argc, argv);
	stack_a = start_list(&info, nbrs, nbr_count);
	return (0);
}
