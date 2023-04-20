/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cost.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 14:27:19 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 18:52:53 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_cost():
*	Calculate the cost of moving each element from stack_b to 
*	stack_a during the sorting process.
*	The cost is based on the position of the element in the stack. 
*	For elements in stack_b, the cost is (size_b - cpy_B->pos) * -1.
*	For elements in stack_a, the cost is (size_a - cpy_B->future_pos) * -1.
*	The size of the cost indicates how far the element is from 
*	its sorted position.
*	If the element is closer to the bottom of the stack, the cost is lower. 
*	If the element is closer to the top of the stack, the cost is higher.
*		- Examle:	
*				size_b = 10;
*				pos = 3;
*				(10 - 3) * -1 = -7;
*		- This negative number (-7) indicates that the cost of moving 
*		  this element to stack_a is low. 
*		- Example:	
*			size_b = 10;
*			pos = 8;
*			(10 - 8) * -1 = -2;
*		- This negative number (-2) indicates that the cost of moving 
*		  this element to stack_a is high.
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cpy_b;
	int		size_a;
	int		size_b;

	cpy_b = *stack_b;
	size_a = ft_lstsize_a(*stack_a);
	size_b = ft_lstsize_a(*stack_b);
	while (cpy_b)
	{
		cpy_b->cost_b = cpy_b->pos;
		if (cpy_b->pos > size_b / 2)
		{
			cpy_b->cost_b = (size_b - cpy_b->pos) * -1;
		}
		cpy_b->cost_a = cpy_b->future_pos;
		if (cpy_b->future_pos > size_a / 2)
		{
			cpy_b->cost_a = (size_a - cpy_b->future_pos) * -1;
		}
		cpy_b = cpy_b->next;
	}
}
