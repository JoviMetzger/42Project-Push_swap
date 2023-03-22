/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_push.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:02 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:58:06 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_pa(): Take the first element at the top of 'b' and put it 
// at the top of 'a'. Do nothing if b is empty
void pb(t_data *data)
{
	t_list *top;
	
    if (data->stack_a)
	{
		top = data->stack_a;
		data->stack_a = top->next;
		top->next = data->stack_b;
		data->stack_b = top;
		printf("pb\n");
	}
}

// ft_pb(): Take the first element at the top of 'a' and put it 
// at the top of 'b'. Do nothing if a is empty.
void pa(t_data *data) ///DONE
{
	t_list *top;
	
    if (data->stack_b)
	{
		top = data->stack_b;
		data->stack_b = top->next;
		top->next = data->stack_a;
		data->stack_a = top;
		printf("pa\n");
	}
}

