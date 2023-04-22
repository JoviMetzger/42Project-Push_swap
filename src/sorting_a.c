/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_A.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 14:22:36 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 17:20:27 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* position_of_LOWindex():
*	Determines the current position of the element with the lowest index.
*		- Assigns a position to each element of the stack.
*		- Identifies the lowest index using the ft_min() function 
*		  and assigns it to low_index.
*		- While iterating over the elements in the stack, 
*		  if the index of the current element equals low_index, 
*		  it assigns the index and position of that element 
*		  to its right index and position.
*		- Otherwise, it moves on to the next element.
*		- Returns the position of the element with the lowest index.
*/
static int	position_of_low_index(t_stack **stack_a)
{
	t_stack	*tmp_a;
	int		low_index;
	int		low_pos;

	assign_position(stack_a);
	tmp_a = *stack_a;
	low_index = ft_min(*stack_a);
	low_pos = tmp_a->pos;
	while (tmp_a)
	{
		if (tmp_a->index == low_index)
		{
			low_index = tmp_a->index;
			low_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (low_pos);
}

/* sorting_A():
*	Once the majority of the stack is sorted, it rotates stack_a until the lowest
*	element/index is at the top. 
*		- If lowest_pos is bigger than half of the size, it is in 
*		  the bottom half of the stack, so it rra(). 
*		- Else, it ra() until it is at the top of the stack.
*/
void	sorting_a(t_stack **stack_a)
{
	int	lowest_pos;
	int	size;

	size = ft_lstsize_a(*stack_a);
	lowest_pos = position_of_low_index(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}
