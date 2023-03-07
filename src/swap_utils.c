/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/05 15:16:42 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/06 10:55:53 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *msg)
{
    ft_putstr(msg);
    ft_putchar('\n');
    exit(0); 
}

void    ft_free(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
