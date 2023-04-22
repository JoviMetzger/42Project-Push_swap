/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_reverse.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 12:52:48 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/22 16:01:26 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* action_reverse(): 
*	Shift down all elements of the stack by 1.
*	The last element becomes the first one.
*/
static void	action_reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	while (prev->next != NULL)
	{
		new = prev;
		prev = prev->next;
	}
	prev->next = *stack;
	new->next = NULL;
	*stack = prev;
}

/* rra(): 
*	Rotates the elements down in stack_a.
*/
void	rra(t_stack **stack_a)
{
	action_reverse(stack_a);
}

/* rrb(): 
*	Rotates the elements down in stack_b.
*/
void	rrb(t_stack **stack_b)
{
	action_reverse(stack_b);
}

/* rrr(): 
*	Does the reverse-rotation in stack_a and stack_b at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	action_reverse(stack_a);
	action_reverse(stack_b);
}
