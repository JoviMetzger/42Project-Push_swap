/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 17:38:41 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:19:41 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int value)
{
	if (value >= 'A' && value <= 'Z')
		return (value = value + 32);
	else
		return (value);
}
