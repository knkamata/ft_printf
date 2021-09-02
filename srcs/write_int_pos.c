/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:08:14 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:08:15 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_pos_prec(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if ((fields->precision >= 0) && ((size_t)fields->precision > len))
	{
		if (fields->flags & FLAG_PLUS)
			cnt += write_sign(fields, '+');
		if (!(fields->flags & FLAG_PLUS) && (fields->flags & FLAG_SPACE))
			cnt += write_sign(fields, ' ');
		cnt += write_zero((size_t)fields->precision - len);
	}
	return (cnt);
}

static int	write_zero_flag(t_fields *fields, size_t *len)
{
	int	cnt;

	cnt = 0;
	if (fields->flags & FLAG_PLUS)
	{
		cnt += write_sign(fields, '+');
		(*len)++;
	}
	if (!(fields->flags & FLAG_PLUS) && (fields->flags & FLAG_SPACE))
	{
		cnt += write_sign(fields, ' ');
		(*len)++;
	}
	cnt += write_zero((size_t)fields->width - *len);
	return (cnt);
}

static int	write_nonzero_flag(t_fields *fields, size_t *len)
{
	int	cnt;

	cnt = 0;
	if (fields->flags & FLAG_PLUS)
	{
		cnt += write_space(fields, *len + 1);
		cnt += write_sign(fields, '+');
	}
	else if (!(fields->flags & FLAG_PLUS) && (fields->flags & FLAG_SPACE))
	{
		cnt += write_space(fields, *len + 1);
		cnt += write_sign(fields, ' ');
	}
	else
		cnt += write_space(fields, *len);
	return (cnt);
}

int	write_pos_left(t_fields *fields, size_t *len)
{
	int	cnt;

	cnt = 0;
	if ((fields->width >= 0) && ((size_t)fields->width > *len))
	{
		if (fields->flags & FLAG_ZERO)
			cnt += write_zero_flag(fields, len);
		else
			cnt += write_nonzero_flag(fields, len);
	}
	return (cnt);
}

int	write_pos_right(t_fields *fields, size_t len)
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
