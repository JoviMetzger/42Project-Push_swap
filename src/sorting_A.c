/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_A.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 21:11:55 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/05 03:12:29 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
void sort_3(t_data *data)
{  
  if (ft_min(data->stack_a) == data->stack_a->content)
  {
    rra(data);
    sa(data);
  }
  else if (ft_max(data->stack_a) == data->stack_a->content)
  {
    ra(data);
    if (!stack_sorted(data->stack_a))
      sa(data);
  }
  else
  {
    if ((int)ft_lstlast_a(data->stack_a)->content == ft_min(data->stack_a))
      rra(data);
    else 
      sa(data);
  }
}

//
void sorting_stack_A(t_data *data)
{
 	while (ft_lstsize_a(data->stack_a) > 3)
		pb(data);
	if (!stack_sorted(data->stack_a))
  	sort_3(data);
}
