/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 17:12:34 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/08 17:31:05 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int value)
{
	if (value >= 'a' && value <= 'z')
		return (value = value -32);
	else
		return (value);
}
