/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:00:14 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/08 17:33:05 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*ptr;

	ptr = (void *)malloc(count * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
