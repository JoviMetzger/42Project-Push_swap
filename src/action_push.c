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
void pb(t_data *data)
{
	t_stack *top;
	
    if (data->stack_a)
	{
		top = data->stack_a;
		data->stack_a = top->next;
		top->next = data->stack_b;
		data->stack_b = top;
		printf("pb\n");
	}
}

// pb(): Take the first element at the top of 'a' and put it 
// at the top of 'b'
void pa(t_data *data) 
{
	t_stack *top;
	
    if (data->stack_b)
	{
		top = data->stack_b;
		data->stack_b = top->next;
		top->next = data->stack_a;
		data->stack_a = top;
		printf("pa\n");
	}
}
