/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:17:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/22 21:09:29 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int matching(char *line, t_stack **stack_a, t_stack **stack_b)
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

static void    executing_input(t_stack **stack_a, t_stack **stack_b)
{
    char *line;
    
    line = get_next_line(0);
    while (line)
    {
        if (!matching(line, stack_a, stack_b))
            write(1, "OK\n", 3);
        free (line);
        line = get_next_line(0);
    }

}

/* main(): 
*	Checks if the input is correct, 
*	in which case it initializes stack a and b, 
*	assigns each value indexes and sorts the stacks.
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
        printStacksData(data->stack_a, data->stack_b);
        executing_input(&data->stack_a, &data->stack_b);
        if (data->stack_b != NULL)
            write(1, "KO\n", 3);
        else if (stack_sorted(data->stack_a))
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
        ft_free(&data->stack_a);
        ft_free(&data->stack_b);
    }
	return (0);
}

//______________________________________________________________________________________________________________________

//	---- 2. Function, prints all the infomation about the given stack. ----
//
// 2.2. printData().
void	printData(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		printf("Content: %d || Index: %d\n",
			stack->content, stack->index);
		stack = stack->next;
		index++;
	}
}

// 2.1. printStacksData().
void	printStacksData(t_stack *stack_a, t_stack *stack_b)
{
	printf("Stack A:\n");
	printData(stack_a);
	printf("Stack B:\n");
	printData(stack_b);
}