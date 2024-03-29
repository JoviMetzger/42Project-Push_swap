/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:55:29 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 14:54:15 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* action_rotate(): 
*	Shift up all elements of the stack by 1.
*	The first element becomes the last one.
*/
static void	action_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

/* ra(): 
*	Rotates the elements up in stack_a.
*/
void	ra(t_stack **stack_a)
{
	action_rotate(stack_a);
	ft_putstr("ra\n");
}

/* rb(): 
*	Rotates the elements up in stack_b.
*/
void	rb(t_stack **stack_b)
{
	action_rotate(stack_b);
	ft_putstr("rb\n");
}

/* rr(): 
*	Does the rotateing in stack_a and stack_b at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	action_rotate(stack_a);
	action_rotate(stack_b);
	ft_putstr("rr\n");
}
