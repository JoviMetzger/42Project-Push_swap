/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 12:49:39 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:16:31 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	unsigned char	*cstr;
	unsigned char	find;
	unsigned int	i;

	cstr = (unsigned char *)str;
	find = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == find)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
