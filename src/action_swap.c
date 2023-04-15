/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_swap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:56:02 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:56:18 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// action_swap(): Swap the first 2 elements at the top of stack. 
// NOTE: very important to swap the index aswell, otherwise swap won't work.
static void action_swap(t_stack *stack) 
{
	int tmp;
	
    if (stack) 
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
		tmp = stack->index;
		stack->index = stack->next->index;
		stack->next->index = tmp;
	}
}

// sa() swaps first 2 elements in stack_a.
void sa(t_stack **stack_a)
{
   	action_swap(*stack_a);
	ft_putstr("sa\n");
}

// sb() swaps first 2 elements in stack_b.
void sb(t_stack **stack_b)
{
   	action_swap(*stack_b);
	ft_putstr("sb\n");
}

// ss(): sa and sb at the same time.
void ss(t_stack **stack_a, t_stack **stack_b) 
{
    action_swap(*stack_a);
    action_swap(*stack_b);
	ft_putstr("ss\n");
}

