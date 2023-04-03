/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:55:29 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:55:35 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// action_rotate_a & ra(): Shift up all elements of stack_a by 1.
// The first element becomes the last one.
static void action_rotate_a(t_data *data)
{
   t_stack *first;
   t_stack *last;
   
   if (data->stack_a)
   {
		first = data->stack_a;
		last = data->stack_a;
		
		while (last->next != NULL)
		{
			last = last->next;	
		}
		data->stack_a = first->next;
		first->next = NULL;
		last->next = first;
   }
}

// action_rotate_b() & rb(): Shift up all elements of stack_b by 1.
// The first element becomes the last one.
static void action_rotate_b(t_data *data)
{
   t_stack *first;
   t_stack *last;
   
   if (data->stack_b)
   {
		first = data->stack_b;
		last = data->stack_b;
		
		while (last->next != NULL)
		{
			last = last->next;	
		}
		data->stack_b = first->next;
		first->next = NULL;
		last->next = first;
   }
}

void ra(t_data *data)
{
   	action_rotate_a(data);
	printf("ra\n");
}

void rb(t_data *data)
{
   	action_rotate_b(data);
	printf("rb\n");
}
// rr(): ra and rb at the same time.
void rr(t_data *data) 
{
    ra(data);
    rb(data);
	printf("rr\n");
}
