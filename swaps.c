/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 18:36:56 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/09 15:07:40 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(char c, t_stack *stack)
{
	int	temp;

	if (stack && stack->next != stack)
	{
		temp = stack->nbrs;
		stack->nbrs = stack->next->nbrs;
		stack->next->nbrs = temp;
	}
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	two_swaps(t_stack stack_a, t_stack stack_b)
{
	swapping(s, stack_a);
	swapping(s, stack_b);
	ft_printf("%c\n", ss);
}
