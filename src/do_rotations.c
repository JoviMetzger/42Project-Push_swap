/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_rotations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 14:11:28 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 18:43:13 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	do_rrr():
*		Reverse rotate both stacks until at least one of them is in 
*		the correct position.
*			- If one of the two cost reaches 0, the stack has been rotated as 
*			  far as possible and the top position is correct.
*			- NOTE: The given cost is negative since both positions are 
*					in the bottom half of their stacks. 
*/
static void	do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/*	do_rr():
*		Rotates both stack_a and stack_b until one of them is in position.
*			- If one of the two cost reaches 0, the stack has been rotated 
*			  as far as possible and the top position is correct. 
*			- NOTE: The given cost is positive since both positions are at 
*					the top half of their stacks.
*/
static void	do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

/*	do_rarra():
*		Rotates stack_b until it is in position. 
*			- If the cost is negative, the stack will be rra().
*			- If it is positive, it will be ra().
*/
static void	do_rarra(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/*	do_rbrrb():
*		Rotates stack_b until it is in position. 
*			- If the cost is negative, the stack will be rrb(). 
*			- If it is positive, it will rb().
*/
static void	do_rbrrb(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/*	do_rotations:
*		Chooses which rotation to make to get element in stack_b to the correct
*		position in stack_a.
*			- If both costs are negative, it calls do_rrr() to reverse rotate 
*			  both stacks until at least one of them is in the correct position.
*			- If both costs are positive, it calls do_rr() to rotate both stacks 
*			  until at least one of them is in the correct position.
*			- Then, it calls do_rarra() to position stack_a top element 
*			  at the top of the stack, and do_rbrrb() to do the same for stack_b.
*			- Finally, it pushes the top element of stack_b onto stack_a by using pa().
*/
void	do_rotations(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(a, b, &cost_a, &cost_b);
	do_rarra(a, &cost_a);
	do_rbrrb(b, &cost_b);
	pa(a, b);
}
