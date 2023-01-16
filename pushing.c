/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:58:41 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/16 19:20:06 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*freenode(t_stack **stack)
{
	t_stack	*freed_node;

	freed_node = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return (freed_node);
	}
(*stack)->prev->next = (*stack)->next;
(*stack)->next->prev = (*stack)->prev;
*stack = (*stack)->next;
	return (freed_node);
}

void	push(char c, t_stack **src, t_stack **dest)
{
	t_stack	push_node;

	push_node = *freenode(src);
	if (dest == NULL)
	{
		push_node.next = &push_node;
		push_node.prev = &push_node;
		*dest = &push_node;
	}
	else
	{
		push_node.next = *dest;
		push_node.prev = (*dest)->prev;
		(*dest)->prev->next = &push_node;
		(*dest)->prev = &push_node;
		*dest = &push_node;
	}
	ft_printf("p%c\n", c);
}
