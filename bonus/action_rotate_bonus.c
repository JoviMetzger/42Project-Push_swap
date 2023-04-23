/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_rotate_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 12:53:10 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 16:07:42 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

/* rb(): 
*	Rotates the elements up in stack_b.
*/
void	rb(t_stack **stack_b)
{
	action_rotate(stack_b);
}

/* rr(): 
*	Does the rotateing in stack_a and stack_b at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	action_rotate(stack_a);
	action_rotate(stack_b);
}
