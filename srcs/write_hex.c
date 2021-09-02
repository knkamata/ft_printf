/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:54:43 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:40 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_hex_prec(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if ((fields->precision >= 0) && ((size_t)fields->precision > len))
		cnt += write_zero((size_t)fields->precision - len);
	return (cnt);
}

static int	write_hex_width(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if ((fields->width >= 0) && ((size_t)fields->width > len))
	{
		if (fields->flags & FLAG_ZERO)
			cnt += write_zero((size_t)fields->width - len);
		else
			cnt += write_space(fields, len);
	}
	return (cnt);
}

static void	write_hex_lower(unsigned int num, t_fields *fields, int *cnt)
{
	if (num != 0 && (fields->flags & FLAG_SHARP))
		*cnt += write(1, "0x", 2);
	ft_putnbr_base(num, "0123456789abcdef", cnt);
}

static void	write_hex_upper(unsigned int num, t_fields *fields, int *cnt)
{
	if (num != 0 && (fields->flags & FLAG_SHARP))
		*cnt += write(1, "0X", 2);
	ft_putnbr_base(num, "0123456789ABCDEF", cnt);
}

int	write_hex(t_fields *fields, int c)
{
	unsigned int	num;
	size_t			len;
	int				cnt;

	cnt = 0;
	num = (unsigned int)va_arg(fields->args, unsigned int);
	len = ft_numlen_base(num, 16);
	if (fields->flags & FLAG_PERIOD)
		cnt += write_hex_prec(fields, len);
	if (!(fields->flags & FLAG_MINUS))
		cnt += write_hex_width(fields, len);
	if (c == 'x')
		write_hex_lower(num, fields, &cnt);
	if (c == 'X')
		write_hex_upper(num, fields, &cnt);
	if (fields->flags & FLAG_MINUS)
		cnt += write_hex_width(fields, len);
	return (cnt);
}
