/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arg_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 12:54:07 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/26 12:14:18 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* ft_is_num(): 
*	Checks if the input contains any non-digit characters. 
*	If it does, the function exits the program with an error message.
*/
static void	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error("Error");
		i++;
	}
}

/* ft_plus_minus(): 
*	Checks if after a '-' or '+' comes a number
*	otherwise, input is invalid.
*/
static void	ft_plus_minus(char *array)
{
	int	i;

	i = 0;
	if (array[0] == '-' || array[0] == '+')
	{
		if (array[1] != '0' && array[1] != '1'
			&& array[1] != '2' && array[1] != '3'
			&& array[1] != '4' && array[1] != '5'
			&& array[1] != '6' && array[1] != '7'
			&& array[1] != '8' && array[1] != '9')
		{	
			ft_error("Error");
		}
	}
	i++;
}

/* ft_empty():
*	Checks if the input array has an empty string.
*		- If the the lenght of the array[i] is 0,
*		  the array[i] is empty.
*/
void	ft_empty(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) == 0)
		{
			ft_error("Error");
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
*		- After that, it checks if the input is valid. 
*/
void	checking_arg(int argc, char **argv)
{
	int	i;
	char	**array;

	i = 0;
	ft_empty(argv);
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
		ft_plus_minus(array[i]);
		i++;
	}
	if (argc == 2)
		ft_free_array(array);
}
