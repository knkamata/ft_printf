/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:54:38 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:43 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static void	flag_zero(t_fields *fields)
{
	if (!fields)
		return ;
	if (!(fields->width) && !(fields->flags & FLAG_PERIOD))
		fields->flags |= FLAG_ZERO;
}

static void	field_digit(int c, t_fields *fields)
{
	if (!fields)
		return ;
	if (fields->flags & FLAG_PERIOD)
		fields->precision = fields->precision * 10 + (c - '0');
	else
		fields->width = fields->width * 10 + (c - '0');
}

static void	field_asterisk(t_fields *fields)
{
	int	arg;

	if (!fields)
		return ;
	arg = va_arg(fields->args, int);
	if (fields->flags & FLAG_PERIOD)
		fields->precision = arg;
	else
		fields->width = arg;
}

int	write_format(const char **format, t_fields *fields)
{
	if (!format || !(*format) || !fields)
		return (0);
	(*format)++;
	while (!(ft_strchr(FT_SPECIFIERS, **format)))
	{
		if (**format == '-')
			fields->flags |= FLAG_MINUS;
		if (**format == '+')
			fields->flags |= FLAG_PLUS;
		if (**format == ' ')
			fields->flags |= FLAG_SPACE;
		if (**format == '#')
			fields->flags |= FLAG_SHARP;
		if (**format == '.')
			fields->flags |= FLAG_PERIOD;
		if (**format == '0')
			flag_zero(fields);
		if (**format == '*')
			field_asterisk(fields);
		if (ft_isdigit(**format))
			field_digit(**format, fields);
		(*format)++;
	}
	return (write_specifiers(format, fields));
}
