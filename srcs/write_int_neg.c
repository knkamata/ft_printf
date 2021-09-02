/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:08:30 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:08:42 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_neg_prec(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if ((fields->precision >= 0) && ((size_t)fields->precision > len))
	{
		cnt += write_sign(fields, '-');
		cnt += write_zero((size_t)fields->precision - len);
	}
	return (cnt);
}

int	write_neg_left(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if ((fields->width >= 0) && ((size_t)fields->width > len))
	{
		if (fields->flags & FLAG_ZERO)
		{
			cnt += write_sign(fields, '-');
			cnt += write_zero((size_t)fields->width - len);
		}
		else
			cnt += write_space(fields, len);
	}
	return (cnt);
}

int	write_neg_right(t_fields *fields, size_t len)
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
