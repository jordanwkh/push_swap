/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 19:51:29 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/19 19:32:42 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->nbrs;
	mid = (*stack)->next->nbrs;
	bot = (*stack)->prev->nbrs;
	if (mid < top && mid < bot && bot > top)
	{
		swapping('a', *stack);
		listtest(*stack, 3);
	}
	else if (mid < top && mid > bot)
	{
		swapping('a', *stack);
		rev_rotate('a', stack);
		listtest(*stack, 3);
	}
	else if (bot > mid && bot < top)
	{
		rotate('a', stack);
		listtest(*stack, 3);
	}
	else if (bot < mid && bot > top)
	{
		swapping('a', *stack);
		rotate('a', stack);
		listtest(*stack, 3);
	}
	else if (top < mid && top > bot)
	{
		rev_rotate('a', stack);
		listtest(*stack, 3);
	}
}
