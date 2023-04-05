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
//-----------------------------------------------------------

// int findPivot(t_stack *stack, int size) {
//     int i = 0;
//     int middle = size / 2; 

//     while (i < middle) { 
//         int j = 0;
//         while (j < size - i - 1) {
//             if (stack->content > stack->next->content) {
//                 int temp = stack->content;
//                 stack->content = stack->next->content;
//                 stack->next->content = temp;
//             }
//             j++;
//         }
//         i++;
//     }

//     int pivot = stack->content;
//     return (pivot);
// }

// void pivot_point(t_data *data, int pivot) 
// {
// 	int start;
	
// 	start = (int)data->stack_a->content;
//   if (start = pivot) 
// 	{
//     pb(data);
// 		pivot_point(data, pivot);
// 	}
//   if (start > pivot)
// 	{
// 		ra(data);
// 		pivot_point(data, pivot);
// 	}
// 	// if (start == pivot)
// 	// {
// 	// 	print("ni");
// 	// }
// }
//----------------------------------------------------

int findMinCommands(int stackA[], int stackB[], int sizeA, int sizeB) {
    int minCommands = -1; // Initialize with a large value to track minimum commands
    int targetNum; // Number to be moved from B to A
    int numCommands; // Number of commands needed to move targetNum to its appropriate position in A

    // Loop through each number in B stack
    for (int i = 0; i < sizeB; i++) {
        targetNum = stackB[i]; // Number to be moved from B to A

        // Find the position of targetNum in A stack
        for (int j = 0; j < sizeA; j++) {
            if (stackA[j] > targetNum) {
                numCommands = i + j + 1; // Number of commands needed to move targetNum to its appropriate position in A
                break;
            }
        }

        // Update minCommands if the current number of commands is smaller than the previously tracked minimum
        if (minCommands == -1 || numCommands < minCommands) {
            minCommands = numCommands;
        }
    }

    return minCommands;
}

//----------------------------------------------------
//
void sorting_stack_A(t_data *data)
{
 	while (ft_lstsize_a(data->stack_a) > 3)
		pb(data);
	if (!stack_sorted(data->stack_a))
  	sort_3(data);
}
