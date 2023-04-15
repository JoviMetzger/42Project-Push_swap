/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_reverse.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:54:57 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:55:03 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// action_reverse(): Shift down all elements of stack by 1.
// The last element becomes the first one.
static void action_reverse(t_stack **stack)
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

void rra(t_stack **stack_a)
{
   	action_reverse(stack_a);
	ft_putstr("rra\n");
}

void rrb(t_stack **stack_b)
{
   	action_reverse(stack_b);
	ft_putstr("rrb\n");
}

// rrr(): rra and rrb at the same time.
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    action_reverse(stack_a);
    action_reverse(stack_b);
	ft_putstr("rrr\n");
}
