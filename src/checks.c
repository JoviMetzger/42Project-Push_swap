/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:46:25 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/20 18:40:42 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_is_num(): 
*	Checks if the input contains any non-digit characters. 
*	If it does, the function exits the program with an error message.
*/
static void	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error("Error, only digit's are allowed");
		i++;
	}
}

/* ft_douple_num(): 
*	Checks for duplicate numbers in the input array 
*	by comparing them using the strcmp() function. 
*	If any duplicates are found, the function exits 
*	the program and displays an error message.
*/
static void	ft_double_num(char **num)
{
	int	i;
	int	j;
	int	comp;

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

/* checking_arg(): 
*	Converts a string input into an array and checks if the 
*	given input is valid.
*		- It first converts the input string into an array using 
*		  the ft_split() function.
*		- Then, it converts each character in the array into an 
*		  integer using the ft_atoi() function.
*		- After that, it checks if the input contains only numerical values, 
*		  and whether there are any duplicates. 
*		  Additionally, it handles specific cases such as the presence 
*		  of negative zero ("-0") values.
*/
void	checking_arg(int argc, char **argv)
{
	int		i;
	char	**array;

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
