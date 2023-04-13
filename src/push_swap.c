/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:07:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 16:15:48 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//___________________________________________
// FOR LEAKS
void ft_systemleaks(void)
{
    system("leaks -q push_swap"); //remove
}
//  - atexit(ft_systemleaks); // USE FOR LEAKS
//____________________________________________

//
void indexing(t_stack *stack)
{
    t_stack  *top;
    t_stack  *min;
    int     index;

    index = 1; //could be 0 aswell;
    while (stack)
    {
        top = stack;
        min = NULL;
        while (top)
        {
            if ((top->index == -1) && (!min || top->content < min->content))
            {
                min = top;
            }
            top = top->next;
        }
        if (min)
        {
            min->index = index++;
        }
        else
        {
            break;
        }
    }
    //print_stack_with_index(stack); //rm
}
//
void	fill_stackA(t_data *data, int argc, char **argv)
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
	if (ft_lstsize_a(data->stack_a) == 1)
		ft_error("Error, input only consists of one number");
}

//
void sorting(t_data *data)
{
	if (ft_lstsize_a(data->stack_a) <= 3)
		sort_3(data);
	else
	{
    	sorting_stack_A(data);
    	sorting_stack_B(data);
	}
}

//
int main(int argc, char **argv)
{
	//atexit(ft_systemleaks); // USE FOR LEAKS
	t_data *data;
		
	if (argc >= 2)
 	{
		checking_arg(argc, argv);
		data = (t_data *)malloc(sizeof(t_data));
		data->stack_a = NULL;
		data->stack_b = NULL;
		fill_stackA(data, argc, argv);
		if (stack_sorted(data->stack_a))
 		 	ft_error("Error, arguments A are already sorted");
		indexing(data->stack_a);
		sorting(data);
		//printStacks(data->stack_a, data->stack_b); //rm
	}
	else
		ft_error("Error, you don't have the correct argument count");
	return (0);
}

// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

void printStack(t_stack *s)
{
	t_stack *tmp;
	
	tmp = s;
    while (tmp != NULL)
	{
		printf("node; %d\n", tmp->content);
		tmp = tmp->next;
	}
}

void printStacks(t_stack *a, t_stack *b) {
    printf("Stack a:\n");
    printStack(a);
    printf("Stack b:\n");
    printStack(b);
}

void print_stack(t_stack *stack) {
    int index = 0;
    while (stack) {
		 printf("Content: %d || Index: %d || Position: %d || Pointer: %p\n", 
               stack->content, stack->index, stack->pos, stack);
        stack = stack->next;
        index++;
    }
}
void print_data(t_data *data) {
    printf("Stack A:\n");
    print_stack(data->stack_a);
    printf("Stack B:\n");
    print_stack(data->stack_b);
}
