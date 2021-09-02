/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:55:01 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:21 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_specifiers(const char **format, t_fields *fields)
{
	int	res;

	if (!format || !(*format) || !fields)
		return (0);
	res = 0;
	if (**format == 'c')
		res = write_char(fields);
	if (**format == 's')
		res = write_str(fields);
	if (**format == 'd' || **format == 'i')
		res = write_int(fields);
	if (**format == 'u')
		res = write_uint(fields);
	if (**format == 'p')
		res = write_ptr(fields);
	if (**format == 'x' || **format == 'X')
		res = write_hex(fields, **format);
	if (**format == '%')
		res = write_pct(fields);
	(*format)++;
	return (res);
}
