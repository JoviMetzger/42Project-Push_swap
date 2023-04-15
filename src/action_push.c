/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_push.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:53:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:54:20 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// action_push(): Pushes the top element of src stack to the top of dest stack.
void	action_push(t_stack **src, t_stack **dest)
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

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	action_push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	action_push(stack_a, stack_b);
	ft_putstr("pb\n");
}
