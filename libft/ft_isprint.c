/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:38:23 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:15:23 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int value)
{
	if (value >= 32 && value <= 126)
		return (value);
	else
		return (0);
}
