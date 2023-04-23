/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 11:46:25 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 18:08:50 by jmetzger      ########   odam.nl         */
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
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error("Error");
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
*		- After that, it checks if the input contains only numerical values. 
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
		i++;
	}
	if (argc == 2)
		ft_free_array(array);
}
