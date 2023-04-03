/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_A.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 21:11:55 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 16:19:27 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
int ft_A_rotate_option(t_data *data)
{
  int option;
  t_stack *current;

  current = data->stack_a;
  option = case_two_a(data, current);
  while (current)
  {
    if (option > case_one_a(data, current))
          option = case_one_a(data, current); 
    if (option > case_two_a(data, current))
      option = case_two_a(data, current);
    if (option > case_three_a(data, current))
      option = case_three_a(data, current);
    if (option > case_four_a(data, current))
      option = case_four_a(data, current); 
    current = current->next; 
  }
  return (option);
}

//
void sort_till_3(t_data *data)
{
  t_stack *current;
  int option;

  while (ft_lstsize_a(data->stack_a) > 3 && !stack_sorted(data->stack_a))
  {
    current = data->stack_a;
    option = ft_A_rotate_option(data);
    while (option >= 0)
    {
      if (option == case_one_a(data, current)) //'case_one'
        option = apply_case_one(data, current->content, 'a');
      else if (option == case_two_a(data, current)) //'case_two'
        option = apply_case_two(data, current->content, 'a');
      else if (option == case_three_a(data, current)) //'case_three'
        option = apply_case_three(data, current->content, 'a');
      else if (option == case_four_a(data, current)) //'case_four'
        option = apply_case_four(data, current->content, 'a');
      else
        current = current->next;
    }
  }
}

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
// void sorting_stack_A(t_data *data)
// {
//   if (ft_lstsize_a(data->stack_a) > 3 && !stack_sorted(data->stack_a))
//     pb(data);
//   if (ft_lstsize_a(data->stack_a) > 3 && !stack_sorted(data->stack_a))
//     sort_till_3(data); 
//   if (!stack_sorted(data->stack_a))
//     sort_3(data);
// }
