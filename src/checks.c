/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:46:25 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 16:59:18 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
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

//
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

//
void ft_minus_zero_check(char *num)
{
    int i;
	
	i = 0;
	if (num[0] == '-' && num[1] == '0')
        ft_error("Error, use of '-0' doesn't work");
	i++;
}

//
void checking_arg(int argc, char **argv)
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
        ft_minus_zero_check(array[i]);
		ft_double_num(array);
		i++;
	}
}