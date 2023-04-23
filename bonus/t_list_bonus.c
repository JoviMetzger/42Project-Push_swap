/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_list_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 14:57:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 19:16:36 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* ft_lstlast_a(): 
*	Returns the last element/node of the stack.
*/
t_stack	*ft_lstlast_a(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		if (stack->next == NULL)
			return (stack);
	}
	return (stack);
}

/* ft_lstnew_a(): 
*	Creates a new element/node inside a stack with the provided value.
*/
t_stack	*ft_lstnew_a(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	return (new);
}

/* ft_lstadd_back_a(): 
*	Adds an element/node to the end of a stack.
*/
void	ft_lstadd_back_a(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_lstlast_a(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/* ft_lstsize_a(): 
*	Returns the number of elements/nodes in the stack.
*/
int	ft_lstsize_a(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
