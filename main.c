/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 14:59:37 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/03/03 18:20:59 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*nbrs;
	int		nbr_count;

	if (argc < 2)
		return (0);
	nbr_count = argc - 1;
	nbrs = parsing(&info, argc, argv);
	stack_a = start_list(&info, nbrs, nbr_count);
	stack_b = NULL;
	if (check_sort(stack_a))
		return (false);
	sorting_all(&stack_a, &stack_b, nbr_count);
	return (0);
}
