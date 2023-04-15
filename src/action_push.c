/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_push.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:53:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:54:20 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// pa(): Take the first element at the top of 'b' and put it 
// at the top of 'a'.
void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *top;
	
    if (*stack_a)
	{
		top = *stack_a;
		*stack_a = top->next;
		top->next = *stack_b;
		*stack_b = top;
		ft_putstr("pb\n");
	}
}

// pb(): Take the first element at the top of 'a' and put it 
// at the top of 'b'
void pa(t_stack **stack_a, t_stack **stack_b) 
{
	t_stack *top;
	
    if (*stack_b)
	{
		top = *stack_b;
		*stack_b = top->next;
		top->next = *stack_a;
		*stack_a = top;
		ft_putstr("pa\n");
	}
}
