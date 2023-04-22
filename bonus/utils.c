/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 13:01:47 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/22 15:56:39 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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