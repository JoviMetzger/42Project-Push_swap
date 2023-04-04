/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/05 15:16:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 13:03:30 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
void ft_error(char *msg)
{
    ft_putstr(msg);
    ft_putchar('\n');
    exit(0); 
}

//
int stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return(0);
		stack = stack->next;
	}
	return(1);
}

//
void    ft_free(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

//
int ft_min(t_stack *stack)
{
	int smallest;

	smallest = stack->content;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content; 
		stack = stack->next;
	}
	return (smallest);
}

//
int ft_max(t_stack *stack)
{
	int biggest;
	
	biggest = stack->content;
	while (stack)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}
