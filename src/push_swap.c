/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:07:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/22 17:20:32 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// - set of integer values
// - 2 stacks, a and b
// - set of instructions to manipulate both stacks.
// - The stack a contains a random amount of negative and/or
//   positive numbers which cannot be duplicated.
// - operations; sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
// -  Error message must display "Error" followed by a ’\n’
// - Errors include for example:
//                  -  some arguments aren’t integers,
//                  - some arguments are bigger than an
//                    integer and/or there are duplicates.
// - If no parameters are specified, the program must not
//   display anything and give the prompt back.
//
// --NOTE--
//		-	int x = 1;
//		-	void *p = &x;
//		-	int *a = (int *)p;
//		-	int y = *(int *)p		->		int x = 1
//			-	which means (int *)p makes sure that the result is a integer pointer to p 
//				and *(int *)p is a dereference from (int *)p, 
//				so the result of y is 1.
//			-	int y = *a;		->		int *y = *(int *)p;
//				BUT int y = *a		-not the same as-	int y = a	
//				& int y = a		-not the same as- int *y = *(int *)p;
//			-	int *y = *(int *)p	-&-		int y = *(int *)p	-> are not the same.

//___________________________________________
// FOR LEAKS
void ft_systemleaks(void)
{
    system("leaks -q push_swap"); //remove
}
//  - atexit(ft_systemleaks); // USE FOR LEAKS
//____________________________________________

static void ft_is_num(char *num)
{
	int i;
	
	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error("Error, please check if your input only consists of digit's");
		i++;
	}
}

static void ft_double_num(char **num)
{
	int i;
	int j;
	int comp;
	
	i = 0;
    while (num[i]) 
	{
		j = i + 1;
        while (num[j]) 
		{
			comp = ft_strcmp(num[i], num[j]);
			if (comp == 0)
				ft_error("Error, some arguments are duplicates");
			j++;
        }
		i++;
    }
}

void ft_checking_arg(int argc, char **argv)
{
	int i;
	char **array;

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
		ft_atoi(array[i]);
		ft_is_num(array[i]);
		ft_double_num(array);
		i++;
	}
}

static void	ft_fill_stackA(t_data *data, int argc, char **argv)
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
		printf("array; %s\n", array[i]);  //rm
		new = ft_lstnew_a(ft_atoi(array[i]));
		ft_lstadd_back_a(&data->stack_a, new);
		i++;
	}
	if (ft_lstsize_a(data->stack_a) == 1)
		ft_error("Error, input only consists of one number");
}
//-
static void ft_stack_sorted(t_data *data)
{
	while (data->stack_a && data->stack_a->next)
	{
		if ((int)data->stack_a->content > (int)data->stack_a->next->content)
			return ;
		data->stack_a = data->stack_a->next;
	}
	ft_error("Error, arguments are already sorted");
}
//-
int main(int argc, char **argv)
{
	//atexit(ft_systemleaks); // USE FOR LEAKS
	t_data *data;
		
	if (argc >= 2)
	{
		ft_checking_arg(argc, argv);
		data = (t_data *)malloc(sizeof(t_data));
		data->stack_a = NULL;
		data->stack_b = NULL;
		ft_fill_stackA(data, argc, argv);
		ft_stack_sorted(data);
		//ft_printStacks(*stack_a); //rm
		//printStacks(data->stack_a, data->stack_b);
		//quickSort(data);
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

// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

void ft_printStacks(t_stack *s) 
{
	t_stack *tmp;
	
	tmp = s;
    printf("Stack contents: \n");
    while (tmp != NULL)
	{
		printf("node; %d\n", tmp->content);
		tmp = tmp->next;
	}
    printf("\n");
}