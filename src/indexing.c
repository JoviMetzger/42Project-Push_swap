/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 14:29:39 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 17:15:33 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* indexing(): 
*	Assigns an index to each value in stack_a. 
*		- This provides a convenient way to sort the stack, 
*		  as indexes can be checked and compared instead of 
*		  the actual values. 
*		- The indexes are assigned based on the order of the values, 
*		  from lowest to highest, starting with '1'.
*/
void	indexing(t_stack *stack)
{
	t_stack	*top;
	t_stack	*min;
	int		index;

	index = 1;
	while (stack)
	{
		top = stack;
		min = NULL;
		while (top)
		{
			if ((top->index == -1) && (!min || top->content < min->content))
			{
				min = top;
			}
			top = top->next;
		}
		if (min)
			min->index = index++;
		else
			break ;
	}
}
