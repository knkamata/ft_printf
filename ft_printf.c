/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:31:18 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 08:31:23 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fields	*init_fields(t_fields *fields)
{
	fields->flags = 0;
	fields->width = 0;
	fields->precision = 0;
	return (fields);
}

int	ft_printf(const char *format, ...)
{
	t_fields	*fields;
	int			res;

	if (!format)
		return (0);
	res = 0;
	fields = (t_fields *)malloc(sizeof(t_fields));
	if (!fields)
		return (-1);
	fields = init_fields(fields);
	va_start(fields->args, format);
	while (*format)
	{
		if (*format == '%')
		{
			res += write_format(&format, fields);
			fields = init_fields(fields);
		}
		else
			res += write(1, format++, 1);
	}
	va_end(fields->args);
	free(fields);
	return (res);
}
