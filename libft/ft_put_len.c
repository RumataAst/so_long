/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:16 by akretov           #+#    #+#             */
/*   Updated: 2023/12/01 16:26:58 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_spec_format(char specifier, va_list arg)
{
	if (specifier == 'c')
		return (putchar_len(va_arg(arg, int)));
	else if (specifier == 's')
		return (putstr_len(va_arg(arg, char *)));
	else if (specifier == 'p')
		return (putptr_len((unsigned long long)va_arg(arg, void *), 0));
	else if (specifier == 'd' || specifier == 'i')
		return (put_nbr_u_hex_len(va_arg(arg, int), 10, 0));
	else if (specifier == 'u')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 16, 1));
	else if (specifier == '%')
		return (putchar_len('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '%')
			count += ft_spec_format(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
