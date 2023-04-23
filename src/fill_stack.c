/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 14:39:00 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 19:15:25 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_free_array(): 
*	Frees each element a 2D array (**array).
*/
char	**ft_free_array(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

/* ft_duplicates(): 
*	Checks for duplicate numbers in the stack. 
*		- Compares each node with the other nodes.
*		- If the current node doesn't match with the other ones it 
*		  moves to the next node.
*/
static void	ft_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other_node;

	current = stack;
	while (current != NULL)
	{
		other_node = current->next;
		while (other_node != NULL)
		{
			if (current->content == other_node->content)
			{
				ft_error("Error");
			}
			other_node = other_node->next;
		}
		current = current->next;
	}
	return ;
}

/* fill_stack(): 
*	Fills stack_a with the provided values.
*		- First, the function converts the input string into 
*		  an array using the ft_split() function.
*		- Next, the function creates a new node for each value in the array 
*		  using the ft_lstnew_a() function and adds them to the back 
*		  of the stack using the ft_lstadd_back_a() function.
*		- The function ft_duplicates() checks if the value inside each content
*		  is more than once in the stack.
*		- Finaly, The function checks the size of the stack. 
*		  If the stack consists of only one node, the function exits 
*		  the program.
*/
void	fill_stack(t_data *data, int argc, char **argv)
{
	t_stack	*new;
	char	**array;
	int		i;

	i = 0;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		array = argv;
	}
	while (array[i])
	{
		new = ft_lstnew_a(ft_atoi(array[i]));
		ft_lstadd_back_a(&data->stack_a, new);
		i++;
	}
	ft_duplicates(data->stack_a);
	if (ft_lstsize_a(data->stack_a) == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
		ft_free_array(array);
}
