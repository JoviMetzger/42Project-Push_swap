/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 19:38:02 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/08 17:27:09 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*dest;
	unsigned int	i;

	dest = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
