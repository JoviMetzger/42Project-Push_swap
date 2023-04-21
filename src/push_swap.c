/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:07:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 19:43:41 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//___________________________________________
// FOR LEAKS
void ft_systemleaks(void)
{
    system("leaks -q push_swap"); //remove
}
//____________________________________________

/* main(): 
*	Checks if the input is correct, 
*	in which case it initializes stack a and b, 
*	assigns each value indexes and sorts the stacks.
*/
int	main(int argc, char **argv)
{
	t_data *data;
	int		stack_size;

	if (argc >= 2)
	{
		//atexit(ft_systemleaks); // USE FOR LEAKS
		checking_arg(argc, argv);
		data = (t_data *)ft_calloc(sizeof(t_data), 1);
		data->stack_a = NULL;
		data->stack_b = NULL;
		fill_stack(data, argc, argv);
		stack_size = ft_lstsize_a(data->stack_a);
		if (stack_sorted(data->stack_a))
		 	ft_error("Error, arguments are already sorted");
		indexing(data->stack_a);
		sorting(data, stack_size);
		// printStacksData(data->stack_a, data->stack_b); // USE FOR PRINTING ALL THE INFORMATION IN A STACK
		// printStacks(data->stack_a, data->stack_b); // USE FOR PRINING STACK VALUES
		ft_free(&data->stack_a);
		ft_free(&data->stack_b);
	}
	else
		ft_error("Error, you don't have the correct argument count");
	return (0);
}

// -----------------------------------------------------------------------
//	        	--- PRINT_FUNCTIONS: ---
//
//
//	----- 1. Function, prints the node of stack_a and stack_b. -----
//
// 1.2. printStack().
void printStack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
    while (tmp != NULL)
	{
		printf("node; %d\n", tmp->content);
		tmp = tmp->next;
	}
}

// 1.1. printStacks().
void printStacks(t_stack *stack_a, t_stack *stack_b) 
{
    printf("Stack a:\n");
    printStack(stack_a);
    printf("Stack b:\n");
    printStack(stack_b);
}

//	---- 2. Function, prints all the infomation about the given stack. ----
//
// 2.2. printData().
void printData(t_stack *stack) 
{
    int index = 0;
    while (stack) {
		 printf("Content: %d || Index: %d || Position: %d || Pointer: %p\n", 
               stack->content, stack->index, stack->pos, stack);
        stack = stack->next;
        index++;
    }
}

// 2.1. printStacksData().
void printStacksData(t_stack *stack_a, t_stack *stack_b) 
{
    printf("Stack A:\n");
    printData(stack_a);
    printf("Stack B:\n");
    printData(stack_b);
}
