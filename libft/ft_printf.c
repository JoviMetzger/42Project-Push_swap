/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 13:07:08 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/09 13:22:35 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 2. Function
int	ft_print_format(va_list arg, const char *str, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (str[i + 1] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str[i + 1] == 'p')
		return (ft_putstr("0x") + ft_put_pointer(va_arg(arg, void *),
				"0123456789abcdef"));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (str[i + 1] == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	if (str[i + 1] == 'x')
		return (ft_hexadecimal(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (str[i + 1] == 'X')
		return (ft_hexadecimal(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (str[i + 1] == '%')
		return (write(1, "%", 1));
	else
		return (ft_putchar(str[i + 1]));
	return (0);
}

// 1. Function
int	ft_printf(const char *format, ...)
{
	int			i;
	int			print_len;
	va_list		arg;

	i = 0;
	print_len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_len += ft_print_format(arg, format, i);
			i++;
		}
		else
		{
			if (format[i] != '%')
				print_len += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(arg);
	return (print_len);
}
