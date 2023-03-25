/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:15:22 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/07 17:27:13 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	result;
	long	end;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == ' ') || (*str == '\f')
		|| (*str == '\n') || (*str == '\r')
		|| (*str == '\t') || (*str == '\v'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	end = result * sign;
	if (end > INT_MAX || end < INT_MIN)
		write(1, "Error\n", 4);
	return (result * sign);
}
