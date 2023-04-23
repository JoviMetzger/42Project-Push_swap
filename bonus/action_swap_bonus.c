/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_swap_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 12:53:32 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 16:07:42 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* action_swap(): 
*	Swap the first 2 elements at the top of the giving stack. 
*	NOTE: very important to swap the index aswell, otherwise swap won't work.
*/
static void	action_swap(t_stack *stack)
{
	int	tmp;

	if (stack)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

/* sa(): 
*	Swaps first 2 elements in stack_a.
*/
void	sa(t_stack **stack_a)
{
	action_swap(*stack_a);
}

/* sb(): 
*	Swaps first 2 elements in stack_b.
*/
void	sb(t_stack **stack_b)
{
	action_swap(*stack_b);
}

/* ss(): 
*	Does the swap in stack_a and stack_b at the same time.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	action_swap(*stack_a);
	action_swap(*stack_b);
}
