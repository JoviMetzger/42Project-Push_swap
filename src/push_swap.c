/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:07:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/08 15:51:12 by jmetzger      ########   odam.nl         */
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
		ft_is_num(array[i]);
		ft_double_num(array);
		i++;
	}
}

static void ft_init_stackA(t_list **stack_a, int argc, char **argv)
{
	t_list *new;
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
		new = ft_lstnew(ft_atoi(array[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data *data;
		
	if (argc >= 2)
	{
		ft_checking_arg(argc, argv);
		data = (t_data *)malloc(sizeof(t_data));
		data->stack_a = NULL;
		data->stack_b = NULL;
		ft_init_stackA(&data->stack_a, argc, argv);
		ft_stack_sorted(data->stack_a);
		//quickSort(*stack_a, *stack_b);
	}
	else
		ft_error("Error, you don't have the correct argument count");
	return (0);
}
