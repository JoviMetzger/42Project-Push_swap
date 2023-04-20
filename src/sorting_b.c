/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_B.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:40:37 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 19:24:44 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting_b(): 
*	- While stack_b is not empty, the function finds 
*	  the right position for the top element of stack_b 
*	  in stack_a using the find_future_position() function.
*	- It then calculates the most cost-effective way to move 
*	  the elements to the right position with the get_cost() function.
*	- The function then applies the correct moves using 
*	  the apply_moves() function.
*	- After all the elements have been moved to stack_a, 
*	  the function checks if stack_a is already sorted. 
*	  If not, it shifts the elements in stack_a until they are 
*	  in order using the sorting_A() function.
*/
static void	sorting_b(t_data *data)
{
	while (data->stack_b)
	{
		find_future_position(&data->stack_a, &data->stack_b);
		get_cost(&data->stack_a, &data->stack_b);
		apply_move(&data->stack_a, &data->stack_b);
	}
	if (!stack_sorted(data->stack_a))
		sorting_a(&data->stack_a);
}

/* push_to_b():
*	Moves all but the last 3 elements from stack_a to stack_b.
*		- The function enters the while loop, while the number 
*		  of elements that have been pushed to stack_b is less 
*		  than half of the size of stack_a.
*		- Inside the loop, the function checks whether the index of the top 
*		  element of stack_a is less or equal to half of the size of stack_a. 
*		  If it is, the function performs the pb() operation to move the element 
*		  from stack_a to stack_b. Else, it does ra() operation to rotate stack_a.
*		- The second while loop pushes the remaining elements in stack_a to stack_b 
*		  with the pb() operation, until there are only 3 elements left in stack_a.
*/
static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize_a(*stack_a);
	pushed = 0;
	i = 0;
	while (i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/* sorting(): 
*	Selects a sorting method based on the number of values to be sorted.
*		- If the stack contains three or less elements, 
*		  the function applies the sort_3() function to sort them.
*		- If the stack contains more than three elements, the function 
*		  applies the push_to_B() function to move the elements to stack_b, 
*		  then sorts the top three elements in the original stack_a using 
*		  the sort_3() function. 
*		  Finally, it applies the sorting_B() function to sort 
*		  the remaining elements in stack_b.
*/
void	sorting(t_data *data, int stack_size)
{
	if (stack_size <= 3)
		sort_3(&data->stack_a);
	else if (stack_size > 3 && !stack_sorted(data->stack_a))
	{
		push_to_b(&data->stack_a, &data->stack_b);
		sort_3(&data->stack_a);
		sorting_b(data);
	}
}
