/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:17:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 19:27:19 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* matching():
*   This function searches for a specific line using the `strcmp()` function, 
*   and performs a corresponding action based on the contents of the line. 
*/
static int	matching(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/* executing_input():
*   This function reads each line from a file and executes 
*   the corresponding command. 
*       - It uses the `get_next_line()` function to read each line, 
*         and matches the line against a list of predefined commands. 
*       - If the line matches a command, the function executes it. 
*       - If the line does not match any commands, the function 
*         displays "KO" and exits.
*/
static void	executing_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!matching(line, stack_a, stack_b))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		free (line);
		line = get_next_line(0);
	}
}

/* main():
*   This function checks if the output of push_swap is correct 
*	    - Checks if the input is formatted correctly and initializes 
*         stacks a and b. 
*       - Checks if the output is correct. 
*       - If the output is correct, the function displays "OK". 
*       - If the output is incorrect, the function displays "KO".
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc >= 2)
	{
		checking_arg(argc, argv);
		data = (t_data *)ft_calloc(sizeof(t_data), 1);
		data->stack_a = NULL;
		data->stack_b = NULL;
		fill_stack(data, argc, argv);
		executing_input(&data->stack_a, &data->stack_b);
		if (data->stack_b != NULL)
			write(1, "KO\n", 3);
		if (stack_sorted(data->stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free(&data->stack_a);
		ft_free(&data->stack_b);
	}
	exit(EXIT_SUCCESS);
}
