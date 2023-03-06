/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 19:51:29 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/03/03 20:12:51 by jhoekstr      ########   odam.nl         */
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
		swapping('a', *stack);
	else if (mid < top && mid > bot)
	{
		swapping('a', *stack);
		rev_rotate('a', stack);
	}	
	else if (bot > mid && bot < top)
		rotate('a', stack);
	else if (bot < mid && bot > top)
	{
		swapping('a', *stack);
		rotate('a', stack);
	}	
	else if (top < mid && top > bot)
		rev_rotate('a', stack);
}

int	lowest_nbr_pos(t_stack **stack_a, int len)
{
	int	i;
	int	low_nbr;
	int	low_nbr_pos;

	low_nbr = (*stack_a)->nbrs;
	low_nbr_pos = 0;
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->nbrs < low_nbr)
		{
			low_nbr = (*stack_a)->nbrs;
			low_nbr_pos = i;
		}
		i++;
		*stack_a = (*stack_a)->next;
	}
	return (low_nbr_pos);
}

void	push_lownbr_to_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	low_nbr_pos;

	low_nbr_pos = lowest_nbr_pos(stack_a, len);
	if (low_nbr_pos > (len / 2))
	{
		while (low_nbr_pos < len)
		{
			rev_rotate('a', stack_a);
			low_nbr_pos++;
		}
	}
	else
	{
		while (low_nbr_pos > 0)
		{
			rotate('a', stack_a);
			low_nbr_pos--;
		}
	}
	push('b', stack_a, stack_b);
}

void	radix(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if ((((*stack_a)->nbrs >> i) & 1) == 1)
			rotate('a', stack_a);
		else
			push('b', stack_a, stack_b);
		len--;
	}	
	while (*stack_b)
	{
		push('a', stack_b, stack_a);
			i++;
	}
}

void	sorting_all(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len > 60)
		radix(stack_a, stack_b, len);
	else
	{
		while (len > 3)
		{
			push_lownbr_to_stack(stack_a, stack_b, len);
			len--;
		}	
		sorting_3 (stack_a);
		while (*stack_b)
		{
			push('a', stack_b, stack_a);
		}
	}	
}
