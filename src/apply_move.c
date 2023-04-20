/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 14:39:24 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 18:35:29 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* convert_nbr(): 
*		Returns the positive value of the given number.
*			- It checks if the number is less than zero. If it is, it multiplies 
*		  	  the value by -1 to make it positive and returns it.
*			- If the number is greater or equal to zero, it returns the original value.
*/
static int	convert_nbr(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

/*	apply_move():
*		Finds the element in stack_b with the lowest cost to move to stack_a
*		and moves it to the correct position in stack_a.
*			- Uses convert_nbr() to convert the negative cost number into a 
*			  positive value.
*			- total_cost is the sum of cost_a and cost_b.
*			- If the total_cost is less than the current cheapest move, 
*			  it updates cheapest, cost_a and cost_b accordingly.
*			- do_move() is called only for the move that had 
*			  a total_cost less than the current cheapest.
*/
void	apply_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cpy_b;
	int		cheapest;
	int		total_cost;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	cpy_b = *stack_b;
	while (cpy_b)
	{
		total_cost = convert_nbr(cpy_b->cost_a) + convert_nbr(cpy_b->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = cpy_b->cost_a;
			cost_b = cpy_b->cost_b;
		}
		cpy_b = cpy_b->next;
	}
	do_rotations(stack_a, stack_b, cost_a, cost_b);
}
