/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:53:45 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:03 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_sa(): Swap the first 2 elements at the top of stack_a. 
// Do nothing if there is only one or no elements.
void sa(t_data *data)
{
	int a;
	int b;
	
    if (data->stack_a) 
	{
		a = data->stack_a->content;
		b = data->stack_a->next->content;
		data->stack_a->content = b;
		data->stack_a->next->content = a;
	}
	printf("sa\n");
}

// ft_sb(): Swap the first 2 elements at the top of stack_b.
// Do nothing if there is only one or no elements.
void sb(t_data *data) 
{
	int a;
	int b;
	
    if (data->stack_b) 
	{
		b = data->stack_b->content;
		a = data->stack_b->next->content;
		data->stack_b->content = a;
		data->stack_b->next->content = b;
	}
	printf("sb\n");
}

// ft_ss(): sa and sb at the same time.
void ss(t_data *data) 
{
    sa(data);
    sb(data);
	printf("ss\n");
}

