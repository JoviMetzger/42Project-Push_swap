/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:53:46 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:19:02 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (i + j < n && str[i + j] == find[j])
			{
				j++;
				if (!find[j])
					return ((char *)(str + i));
			}
		}
		i++;
	}
	return (0);
}
