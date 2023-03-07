/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 08:55:44 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:14:23 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if (((alnum >= 'a' && alnum <= 'z') || (alnum >= 'A' && alnum <= 'Z'))
		|| (alnum >= '0' && alnum <= '9'))
		return (alnum);
	else
		return (0);
}
