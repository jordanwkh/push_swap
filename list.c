/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 19:11:16 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/06 21:10:49 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbrs = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*start_list(t_info *info, int *arr, int nbrs_count)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	stack_a = lstnew(arr[0]);
	if (!stack_a)
		return_error(info, true);
	head = stack_a;
	i = 1;
	while (i < nbrs_count)
	{
		stack_a->next = lstnew(arr[i]);
		if (!stack_a->next)
			return_error(info, true);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = head;
	stack_a->next->prev = stack_a;
	return (head);
}

bool	check_sort(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (stack->next != head)
	{
		if (stack->nbrs > stack->next->nbrs)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// void	listtest(t_stack *stack, int nbrlist)
// {
// 	int	i;

// 	i = 1;
// 	while (i <= nbrlist)
// 	{
// 		printf("node[%d]\t\t%d\n", i, stack->nbrs);
// 		i++;
// 		stack = stack->next;
// 	}	
// 	printf("\n");
// }
