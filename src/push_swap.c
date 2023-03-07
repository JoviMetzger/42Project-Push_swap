/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:07:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/07 17:32:36 by jmetzger      ########   odam.nl         */
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
			ft_error("Error, some arguments aren’t integers");
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
	long tmp;
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
		tmp = ft_atoi(array[i]);
		//printf("tmp; %ld\n", tmp);
		ft_is_num(array[i]);
		ft_double_num(array);
		//ft_is_sorted(tmp);
		i++;
	}
}

int main(int argc, char **argv)
{
	atexit(ft_systemleaks); // USE FOR LEAKS
	// t_swap *stack_a;
	// t_swap *stack_b;
	
	if (argc >= 2)
	{
		ft_checking_arg(argc, argv);
		printf("success");
		// stack_a = (t_swap *)malloc(sizeof(t_swap));
		// stack_b = (t_swap *)malloc(sizeof(t_swap));
		//ft_sort_stack(stack_a, stack_b);
		//ft_shellSort(data, size);
		//ft_printArray(data, size);
	}
	else
		ft_error("Error, you don't have the correct argument count");
	return (0);
}
