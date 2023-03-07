/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 19:11:56 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/08 17:29:35 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	while (*str != (char)n)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}
