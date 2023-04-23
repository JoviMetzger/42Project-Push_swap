/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 13:01:47 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 19:16:31 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	exit(EXIT_FAILURE);
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
