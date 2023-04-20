/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_position.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 14:11:04 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 18:50:36 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	assign_position():
*		Assigns a position to each element of the stack.
*		- Example stack:
*				content:	 9	 1	 6	 4
*				index:		[4]	[1]	[3]	[2]
*				position:	<0>	<1>	<2>	<3>
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

/*	get_position_in_a():
*		Finds the position of the largest number in stack_a that 
*		is smaller than the given index of stack_b. 
*			- Checks whether the index of the current element 
*			  is greater than the index from stack_b(B_idx) 
*			  and less than the biggest index (biggest_idx).
*			  biggest_idx is in the beginning INT_MAX. 
*			- If it is, then the biggest_idx is updated to 
*			  the index of the current element, 
*			  and current_pos is updated to the position of the current element. 
*			- If no larger element is found during the first loop, 
*			  then the function loops through stack_a again and checks 
*			  whether the index of the current element is less than biggest_idx. 
*			- If it is, then the biggest_idx variable is updated to 
*			  the index of the current element, and the current_pos variable
*			  is updated to the position of the current element.
*			- Returns the value of current_pos.
*/
static int	get_position_in_a(t_stack **stack_a, int B_idx, \
									int current_pos, int biggest_idx)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > B_idx && tmp_a->index < biggest_idx)
		{
			biggest_idx = tmp_a->index;
			current_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (biggest_idx != INT_MAX)
		return (current_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < biggest_idx)
		{
			biggest_idx = tmp_a->index;
			current_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (current_pos);
}

/*	find_future_position():
*		Assigns a 'future' position in stack_a to each element of stack_b.
*		The 'future' position is the spot in stack_a where the element in 
*		stack_b needs to go to be sorted correctly. This position will be 
*		used to calculate the cost of moving each element to its 
*		'future' position in stack_a.
*			- We assaign positions to each element in stack_a and stack_b
*			  using assign_position().
*			- While iterating through tmp_b, we look for the postition of 
*			  that element in stack_a with the function get_position_in_A() 
*			  and assign it to future_pos for the elements in stack_b.
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
		current_pos = get_position_in_a(stack_a, tmp_b->index, \
			current_pos, INT_MAX);
		tmp_b->future_pos = current_pos;
		tmp_b = tmp_b->next;
	}
}
