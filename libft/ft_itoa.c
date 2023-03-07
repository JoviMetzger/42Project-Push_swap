/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 11:52:28 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:15:34 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_division(int len)
{
	int		div;

	div = 1;
	while (len > 0)
	{
		div = div * 10;
		len--;
	}
	return (div);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;
	long int		nb;
	int				div;

	len = ft_len(n);
	nb = n;
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (result == 0)
		return (NULL);
	div = ft_division(len - 1);
	len = 0;
	if (nb < 0)
	{
		result[len++] = '-';
		nb = nb * -1;
	}
	while (div > 0)
	{
		result[len++] = (nb / div % 10) + '0';
		div = div / 10;
	}
	result[len] = '\0';
	return (result);
}
