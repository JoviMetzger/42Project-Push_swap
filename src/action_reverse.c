/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_reverse.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:39 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:39 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_rra(): Shift down all elements of stack_a by 1.
// The last element becomes the first one.
void rra(t_data *data)
{
	t_stack *prev_last;
	t_stack *last;
	
    if (data->stack_a)
	{
		last = data->stack_a;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}	
		prev_last->next = NULL;
		last->next = data->stack_a;
		data->stack_a = last;	
	}
	printf("rra\n");
}

// ft_rrb(): Shift down all elements of stack_b by 1.
// The last element becomes the first one.
void rrb(t_data *data)
{
	t_stack *prev_last;
	t_stack *last;
	
    if (data->stack_b)
	{
		last = data->stack_b;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}	
		prev_last->next = NULL;
		last->next = data->stack_b;
		data->stack_b = last;	
	}
	printf("rrb\n");
}

// ft_rrr(): rra and rrb at the same time.
void rrr(t_data *data)
{
    rra(data);
    rrb(data);
	printf("rrr\n");
}
