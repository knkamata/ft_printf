/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 22:22:57 by kkamata           #+#    #+#             */
/*   Updated: 2021/08/23 13:24:10 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifying(const char *format, va_list *args)
{
	int	res;

	if (!format || !args)
		return (0);
	res = 0;
	if (*format == 'c')
		res = stdout_char(args);
	if (*format == 's')
		res = stdout_str(args);
	if (*format == 'd' || *format == 'i')
		res = stdout_int(args);
	if (*format == 'u')
		res = stdout_uint(args);
	if (*format == 'p')
		res = stdout_ptr(args);
	if (*format == 'x' || *format == 'X')
		res = stdout_hex(args, *format);
	if (*format == '%')
		res = write(1, "%", 1);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			res;

	if (!format)
		return (0);
	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			res += specifying(format + 1, &args);
			format++;
		}
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (res);
}
