/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:55:07 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:18 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_uint_width(t_fields *fields, size_t len)
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

int	write_uint(t_fields *fields)
{
	char			*num;
	size_t			len;
	unsigned int	tmp;
	int				cnt;

	cnt = 0;
	tmp = va_arg(fields->args, unsigned int);
	num = ft_uitoa(tmp);
	if (!num)
		return (0);
	len = ft_strlen(num);
	if ((fields->flags & FLAG_PERIOD) \
			&& (fields->precision >= 0) && ((size_t)fields->precision > len))
		cnt += write_zero((size_t)fields->precision - len);
	if (!(fields->flags & FLAG_MINUS))
		cnt += write_uint_width(fields, len);
	cnt += write(1, num, len);
	if (fields->flags & FLAG_MINUS)
		cnt += write_uint_width(fields, len);
	free(num);
	return (cnt);
}
