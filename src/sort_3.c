/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 21:11:55 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 17:19:25 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_3(): 
*	Sorts a stack of 3 numbers based on their indices, rather than their 
*	values.
*		- Check if the first index of the stack is the smallest index. 
*		  If it is, apply the rra() and sa() operations.
*		- If the first index is not the smallest index, check if it is 
*		  the biggest index. 
*		  If it is, apply the ra() operation and check if 
*		  the stack is sorted. 
*		  If it is not, apply the sa() operation.
*		- If the first index is neither the smallest nor the biggest,
*		  check if 
*		  the last index is the smallest index. If it is, apply 
*		  the rra() operation. 
*		  If the last index is the biggest index, apply the sa() operation.
*		- Finally, check if the first index is bigger than 
*		  the index next to it. 
*		  If it is, apply the sa() operation.
*/
void	sort_3(t_stack **stack)
{
	if (stack_sorted(*stack))
		return ;
	if ((*stack)->index == ft_min(*stack))
	{
		rra(stack);
		sa(stack);
	}
	else if ((*stack)->index == ft_max(*stack))
	{
		ra(stack);
		if (!stack_sorted(*stack))
			sa(stack);
	}
	else
	{
		if ((int)ft_lstlast_a(*stack)->index == ft_min(*stack))
			rra(stack);
		else
			sa(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
