/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_cost.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 14:27:19 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 20:53:02 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculate_cost_b():
*	NOTE: cost_b is the cost of getting the element to the top of the stack_b.
*	This function calculates the cost of moving an element to the top of stack_b.
*		- If the current_pos is greater than the middle position, 
*		  it calculates the cost by subtracting the current_pos from 
*		  the end of the stack, and then multiplying the result by -1.
*/
static int	calculate_cost_b(int current_pos, int size_b)
{
	int	cost_b;

	cost_b = current_pos;
	if (current_pos > size_b / 2)
	{
		cost_b = (size_b - current_pos) * -1;
	}
	return (cost_b);
}

/* calculate_cost_a():
*	NOTE: cost_a is the cost of getting the element to 
*		  the right position in stack_a.
*	The function calculates the cost of moving the element 
*	to stack_b by subtracting the future_pos from the middle position 
*	of the stack_a. 
*		- If the future_pos is greater than the middle position, 
*		  it calculates the cost by subtracting the future_pos from the end 
*		  of the stack, and then multiplying the result by -1.
*/
static int	calculate_cost_a(int future_pos, int size_a)
{
	int	cost_a;

	cost_a = future_pos;
	if (future_pos > size_a / 2)
	{
		cost_a = (size_a - future_pos) * -1;
	}
	return (cost_a);
}

/* calculate_cost():
*	Calculate the cost of moving each element from stack_b to 
*	stack_a during the sorting process.
*	The cost is based on the position of the element in the stack. 
*		- It iterates through each node of stack_b and calculates 
*		  the cost of moving the element to it possible position in stack_a.
*		- It stores the calculated costs in the cost_a and cost_b variables 
*		  of the corresponding node.
*	NOTE: cost_b is the cost of getting the element to the top of the stack_b.
* 		  cost_a is the cost of getting the element to the right position in stack_a.
*/
void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *stack_b;
	size_a = ft_lstsize_a(*stack_a);
	size_b = ft_lstsize_a(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = calculate_cost_b(tmp_b->pos, size_b);
		tmp_b->cost_a = calculate_cost_a(tmp_b->future_pos, size_a);
		tmp_b = tmp_b->next;
	}
}
