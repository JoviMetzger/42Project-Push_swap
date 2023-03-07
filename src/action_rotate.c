/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_rotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:21 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:57:26 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_ra: Shift up all elements of stack_a by 1.
// The first element becomes the last one.
void ft_ra(int *stack, int *top)
{
    int i;
    int tmp;

    if (*top > 0)
    {
        tmp = stack[*top];
        i = *top;
        while (i > 0)
        {
            stack[i] = stack[i - 1];
            i--;
        }
        stack[0] = tmp;
    }
    ft_printf("ra\n"); 
}

// ft_rb(): Shift up all elements of stack_b by 1.
// The first element becomes the last one.
void ft_rb(int *stack, int *top)
{
    int i;
    int tmp;

    if (*top > 0)
    {
        tmp = stack[*top];
        i = *top;
        while (i > 0)
        {
            stack[i] = stack[i - 1];
            i--;
        }
        stack[0] = tmp;
    }
    ft_printf("rb\n"); 
}

// ft_rr(): ra and rb at the same time.
void ft_rr(int *stack_a, int *top_a, int *stack_b, int *top_b)
{
    ft_ra(int *stack_a, int *top_a);
    ft_rb(int *stack_b, int *top_b);
    ft_printf("rr\n"); 
}
