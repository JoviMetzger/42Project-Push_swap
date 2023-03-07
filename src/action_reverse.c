/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_reverse.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:39 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:39 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_rra(): Shift down all elements of stack_a by 1.
// The last element becomes the first one.
void ft_rra(int *stack, int *top)
{
    int tmp;
    int i;

    if (*top > 0)
    {
        tmp = stack[0];
        i = 0;
        while (i < *top)
        {
            stack[i] = stack[i + 1];
            i++;
        }
        stack[*top] = tmp;
    }
    ft_printf("rra\n"); 
}

// ft_rrb(): Shift down all elements of stack_b by 1.
// The last element becomes the first one.
void ft_rrb(int *stack, int *top)
{
    int tmp;
    int i;

    if (*top > 0)
    {
        tmp = stack[0];
        i = 0;
        while (i < *top)
        {
            stack[i] = stack[i + 1];
            i++;
        }
        stack[*top] = tmp;
    }
    ft_printf("rrb\n"); 
}

// ft_rrr(): rra and rrb at the same time.
void ft_rrr(int *stack_a, int *top_a, int *stack_b, int *top_b)
{
    ft_rra(int *stack_a, int *top_a);
    ft_rrb(int *stack_b, int *top_b);
    ft_printf("rrr\n"); 
}
