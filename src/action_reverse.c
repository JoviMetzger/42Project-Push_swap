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

// action_reverse_a() & rra(): Shift down all elements of stack_a by 1.
// The last element becomes the first one.
static void action_reverse_a(t_data *data)
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
}

// action_reverse_b() & rrb(): Shift down all elements of stack_b by 1.
// The last element becomes the first one.
static void action_reverse_b(t_data *data)
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
}

void rra(t_data *data)
{
   	action_reverse_a(data);
	printf("rra\n");
}

void rrb(t_data *data)
{
   	action_reverse_b(data);
	printf("rrb\n");
}

// rrr(): rra and rrb at the same time.
void rrr(t_data *data)
{
    action_reverse_a(data);
    action_reverse_b(data);
	printf("rrr\n");
}
