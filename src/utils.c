/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/05 15:16:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 19:31:43 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_free(): 
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* ft_error(): 
*	Displays the given error message to the standard output and exits the program.
*/
void	ft_error(char *msg)
{
	ft_putstr(msg);
	ft_putchar('\n');
	exit(1);
}

/* stack_sorted(): 
*	Checks if the given stack is sorted.
*/
int	stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* ft_min(): 
*	Finds the smallest index of the given stack.
*/
int	ft_min(t_stack *stack)
{
	int	smallest;

	smallest = stack->index;
	while (stack)
	{
		if (stack->index < smallest)
			smallest = stack->index;
		stack = stack->next;
	}
	return (smallest);
}

/* ft_max(): 
*	Finds the biggest index of the given stack.
*/
int	ft_max(t_stack *stack)
{
	int	biggest;

	biggest = stack->index;
	while (stack)
	{
		if (stack->index > biggest)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
}
