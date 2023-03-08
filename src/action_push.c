/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_push.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:54:02 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/16 11:58:06 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// *top is the pointer to the top element of *stack.
// ft_pa(): Take the first element at the top of 'b' and put it 
// at the top of 'a'. Do nothing if b is empty
void pa(int *stack_a, int *top_a, int *stack_b, int *top_b)
{
  if (*top_b >= 0)
    stack_a[++(*top_a)] = stack_b[(*top_b)--];
  ft_printf("pa\n");  
}

// ft_pb(): Take the first element at the top of 'a' and put it 
// at the top of 'b'. Do nothing if a is empty.
void pb(int *stack_a, int *top_a, int *stack_b, int *top_b)
{
  if (*top_a >= 0)
    stack_b[++(*top_b)] = stack_a[(*top_a)--];
  ft_printf("pb\n"); 
}
