/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 16:01:08 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/01/19 19:18:59 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char c, t_stack **stack)
{
	*stack = (*stack)->next;
	ft_printf("r%c\n", c);
}

void	duo_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}

void	rev_rotate(char c, t_stack **stack)
{
	*stack = (*stack)->prev;
	ft_printf("rr%c\n", c);
}

void	duo_rev_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_printf("rrr\n");
}
