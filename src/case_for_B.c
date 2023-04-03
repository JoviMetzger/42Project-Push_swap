/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   case_for_B.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:51:17 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 13:05:51 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  ra - rb
int case_one_b(t_data *data, t_stack *current_nbr)
{
    int i;
    
    i = future_index_in_a(data->stack_a, current_nbr->content);
   if (i < find_index(data->stack_b, current_nbr->content))
        i = find_index(data->stack_b, current_nbr->content);
    return (i);
}

//  rra - rrb 
int case_two_b(t_data *data, t_stack *current_nbr)
{
     int i;

    i = 0;
    if (future_index_in_a(data->stack_a, current_nbr->content))
        i = ft_lstsize_a(data->stack_a) - future_index_in_a(data->stack_a, current_nbr->content);
    if ((i < (ft_lstsize_a(data->stack_b) - find_index(data->stack_b, current_nbr->content)))) 
        i = ft_lstsize_a(data->stack_b) - find_index(data->stack_b, current_nbr->content);
    return (i);
}

// rra - rb
int case_three_b(t_data *data, t_stack *current_nbr)
{
    int i;

    i = 0;
    if (find_index(data->stack_b, current_nbr->content))
        i = ft_lstsize_a(data->stack_b) - find_index(data->stack_b, current_nbr->content);
    i = future_index_in_a(data->stack_a, current_nbr->content) + i;
    return (i);
}

//  ra - rrb
int case_four_b(t_data *data, t_stack *current_nbr)
{
    int i;
    
    i = 0;
    if (future_index_in_a(data->stack_a, current_nbr->content))
        i = ft_lstsize_a(data->stack_b) - current_nbr->index;
    i = find_index(data->stack_b, current_nbr->content) + i;
    return (i);
}

//
int future_index_in_a(t_stack *stack, int current_nbr)
{
    int new_i;
    t_stack *tmp_nxt;
    
    new_i = 1;
    if (current_nbr < stack->content && current_nbr > ft_lstlast_a(stack)->content)
        new_i = 0;
    else if (current_nbr > ft_max(stack) || current_nbr < ft_min(stack))
        new_i = find_index(stack, ft_min(stack));
    else
    {
        tmp_nxt = stack->next;
        while (stack->content > current_nbr || tmp_nxt->content < current_nbr)
        {
            stack = stack->next;
            tmp_nxt = stack->next;
            new_i++;
        }
    }
    return (new_i);    
}