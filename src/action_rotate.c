/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_rotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:21 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:26 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_ra: Shift up all elements of stack_a by 1.
// The first element becomes the last one.
void ra(t_data *data)
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
	printf("ra\n");
}

// ft_rb(): Shift up all elements of stack_b by 1.
// The first element becomes the last one.
void rb(t_data *data)
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
	printf("rb\n");
}

// ft_rr(): ra and rb at the same time.
void rr(t_data *data) 
{
    ra(data);
    rb(data);
	printf("rr\n");
}
