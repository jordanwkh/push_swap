/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:58:41 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/09 14:58:36 by jhoekstr      ########   odam.nl         */
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
}
(*stack)->prev->next = (*stack)->next;
(*stack)->next->prev = (*stack)->prev;
