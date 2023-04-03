/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_cases.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:52:04 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 14:56:32 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  ra - rb        
int apply_case_one(t_data *data, int current, int c)
{
    if (c == 'a')
    {
        while (data->stack_a->content != current && future_index_in_b(data->stack_b, current) > 0)
            rr(data);
        while (data->stack_a->content != current)
            ra(data);
        while (future_index_in_b(data->stack_b, current) > 0)
            rb(data);
        pb(data);
    }
    if (c == 'b')
    {
        while (data->stack_b->content != current && future_index_in_a(data->stack_a, current) > 0)
            rr(data);
        while (data->stack_b->content != current)
            rb(data);
        while (future_index_in_a(data->stack_a, current) > 0)
            ra(data);
        pa(data);
    }
    return (-1);
}

//  rra - rrb
int apply_case_two(t_data *data, int current, int c)
{
    if (c == 'a')
    {
        while (data->stack_a->content != current && future_index_in_b(data->stack_b, current) > 0)
            rrr(data);
        while (data->stack_a->content != current)
            rra(data);
        while (future_index_in_b(data->stack_b, current) > 0)
            rrb(data);
        pb(data);
    }
    if (c == 'b')
    {
        while (data->stack_b->content != current && future_index_in_a(data->stack_a, current) > 0)
            rrr(data);
        while (data->stack_b->content != current)
            rrb(data);
        while (future_index_in_a(data->stack_a, current) > 0)
            rra(data);
        pa(data);
    }
    return (-1);
}

// rra - rb
int apply_case_three(t_data *data, int current, int c)
{
    if (c == 'a')
    {
        while (data->stack_a->content != current)
            rra(data);
        while (future_index_in_b(data->stack_b, current) > 0)
            rb(data);
        pb(data);
    }
    if (c == 'b')
    {
        while (future_index_in_a(data->stack_a, current) > 0)
            rra(data);
        while (data->stack_b->content != current)
            rb(data);
        pa(data);
    }
    return (-1);
}

//  ra - rrb
int apply_case_four(t_data *data, int current, int c)
{
    if (c == 'a')
    {
        while (data->stack_a->content != current)
            ra(data);
        while (future_index_in_b(data->stack_b, current) > 0)
            rrb(data);
        pb(data);
    }
    if (c == 'b')
    {
        while (future_index_in_a(data->stack_a, current) > 0)
            ra(data);
        while (data->stack_b->content != current)
            rrb(data);
        pa(data);
    }
    return (-1);
}
