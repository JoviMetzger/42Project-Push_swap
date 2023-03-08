/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:53:45 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:03 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_sa(): Swap the first 2 elements at the top of stack_a. 
// Do nothing if there is only one or no elements.
void sa(int *stack, int *top)
{
    int tmp;

    if (*top > 0)
    {
        tmp = stack[*top];
        stack[*top] = stack[*top - 1];
        stack[*top - 1] = tmp;
    }
    ft_printf("sa\n");
}

// ft_sb(): Swap the first 2 elements at the top of stack_b.
// Do nothing if there is only one or no elements.
void sb((int *stack, int *top))
{
    int tmp;

    if (*top > 0)
    {
        tmp = stack[*top];
        stack[*top] = stack[*top - 1];
        stack[*top - 1] = tmp;
    }
    ft_printf("sb\n"); 
}

// ft_ss(): sa and sb at the same time.
void ss(int *stack_a, int *top_a, int *stack_b, int *top_b)
{
    sa(int *stack_a, int *top_a);
    sb(int *stack_b, int *top_b); 
    ft_printf("ss\n");
}
