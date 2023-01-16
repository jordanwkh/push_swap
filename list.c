/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 19:11:16 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/16 18:49:06 by jhoekstr      ########   odam.nl         */
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
	return (new);
}

// t_stack	lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*save;

// 	if (!*lst)
// 		*lst = new;
// 	else
// 	{
// 		save = ft_lstlast(*lst);
// 		save->next = new;
// 	}	
// }

t_stack	*start_list(t_info *info, int *arr, int argc)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	stack_a = lstnew(arr[0]);
	if (!stack_a)
		return_error(info, "arr");
	head = stack_a;
	i = 1;
	while (i < (argc - 1))
	{
		stack_a->next = lstnew(arr[i]);
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
