/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 17:53:06 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/08 17:29:10 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned int	i;

	dest = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		dest[i] = ch;
		i++;
	}
	return (str);
}
