/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_push_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 12:52:20 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 16:07:42 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* action_push(): 
*	Pushes the top element of src-stack to the top of dest-stack.
*/
static void	action_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (dest == NULL)
		*dest = tmp;
	else
	{
		tmp->next = *dest;
		*dest = tmp;
	}
}

/* pa(): 
*	Pushes the first element from stack_b to stack_a.
*/
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	action_push(stack_b, stack_a);
}

/* pb(): 
*	Pushes the first element from stack_a to stack_b.
*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	action_push(stack_a, stack_b);
}
