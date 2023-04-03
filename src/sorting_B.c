/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_B.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:40:37 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 16:20:06 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
int ft_B_rotate_option(t_data *data)
{
  int option;
  t_stack *current;

  current = data->stack_b;
  option = case_two_b(data, current);
  while (current)
  {
    if (option > case_one_b(data, current))
      option = case_one_b(data, current);
    if (option > case_two_b(data, current))
      option = case_two_b(data, current);
    if (option > case_three_b(data, current))
      option = case_three_b(data, current);
    if (option > case_four_b(data, current))
      option = case_four_b(data, current); 
    current = current->next; 
  }
  return (option);
}

//
void sorting_stack_B(t_data *data)
{
  t_stack *current;
  int option;
  
  while (ft_lstsize_a(data->stack_b))
  {
    current = data->stack_b;
    option = ft_B_rotate_option(data);
    while (option >= 0)
    {
      if (option == case_one_b(data, current))
        option = apply_case_one(data, current->content, 'b');
      else if (option == case_two_b(data, current))
        option = apply_case_two(data, current->content, 'b');
      else if (option == case_three_b(data, current))
        option = apply_case_three(data, current->content, 'b');
      else if (option == case_four_b(data, current))
        option = apply_case_four(data, current->content, 'b');
      else
        current = current->next;
    }
  }
}
