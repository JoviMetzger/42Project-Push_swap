/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_position.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 14:11:04 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 19:31:51 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* assign_position():
*	Assigns a position to each element of the stack.
*	- Example stack:
*			content:	 9	 1	 6	 4
*			index:		[4]	[1]	[3]	[2]
*			position:	<0>	<1>	<2>	<3>
*/
void	assign_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* find_bigger_index():
*   The function looks for the index of the element that 
*   is bigger and closest to B_idx. 
*       - It checks each element index to see if its bigger 
*         than B_idx and less than biggest_idx. 
*         If it is, then biggest_idx is updated to 
*         the index of that element. 
*       - Once all elements of the stack have been checked, 
*         it returns biggest_idx. 
*/
static int	find_bigger_index(t_stack *stack_a, int B_idx)
{
	int	biggest_idx;

	biggest_idx = INT_MAX;
	while (stack_a)
	{
		if (stack_a->index > B_idx && stack_a->index < biggest_idx)
		{
			biggest_idx = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (biggest_idx);
}

/* find_position():
*	The function looks for the element with the given index, 
*   and returns the position of that element.
*       - First checks each element if the index matches the input index. 
*         If it does, position updates to the position of that element, 
*         which is saved in stack_a_pos. 
*       - Once the element with the given index has been found, 
*         it returns the position.
*/
static int	find_position(t_stack *stack_a, int biggest_idx)
{
	int	position;

	position = 0;
	while (stack_a)
	{
		if (stack_a->index == biggest_idx)
		{
			position = stack_a->pos;
			break ;
		}
		stack_a = stack_a->next;
	}
	return (position);
}

/* get_position_in_a():
*   The function calculates the position of the element 
*   in stack_a that should be moved to the top of the stack. 
*       - find_bigger_index() gets the index of the element 
*         in stack_a that is bigger and closest to B_idx. 
*       - find_position() gets the position of that element in the stack. 
*       - If find_bigger_index() returns the INT_MAX value, 
*         which means that there are no elements in stack_a 
*         that are bigger than B_idx. 
*       - Then find_bigger_index() is called again with -1 as 
*         the second argument to find the largest element in 
*         the stack, and find_position() is called again to 
*         get the position of that element. 
*       - Returns the value of current_pos.
*/
static int	get_position_in_a(t_stack **stack_a, int B_idx)
{
	int	biggest_idx;
	int	position;

	biggest_idx = find_bigger_index(*stack_a, B_idx);
	position = find_position(*stack_a, biggest_idx);
	if (biggest_idx == INT_MAX)
	{
		biggest_idx = find_bigger_index(*stack_a, -1);
		position = find_position(*stack_a, biggest_idx);
	}
	return (position);
}

/* find_future_position():
*	Assigns a 'future' position in stack_a to each element of stack_b.
*	The 'future' position is the spot in stack_a where the element in 
*	stack_b needs to go to be sorted correctly. This position will be 
*	used to calculate the cost of moving each element to its 
*	'future' position in stack_a.
*		- We assaign positions to each element in stack_a and stack_b
*		  using assign_position().
*		- While iterating through tmp_b, we look for the postition of 
*		  that element in stack_a with the function get_position_in_a() 
*		  and assign it to future_pos for the elements in stack_b.
*/
void	find_future_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		current_pos;

	tmp_b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	current_pos = 0;
	while (tmp_b)
	{
		current_pos = get_position_in_a(stack_a, tmp_b->index);
		tmp_b->future_pos = current_pos;
		tmp_b = tmp_b->next;
	}
}
