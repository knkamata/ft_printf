/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:55:04 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:20 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_char(t_fields *fields)
{
	char	c;
	int		cnt;

	cnt = 0;
	c = va_arg(fields->args, int);
	if (!(fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, 1);
	cnt += write(1, &c, 1);
	if ((fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, 1);
	return (cnt);
}

int	write_str(t_fields *fields)
{
	char	*str;
	size_t	len;
	int		cnt;

	cnt = 0;
	str = va_arg(fields->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((fields->flags & FLAG_PERIOD) \
			&& (fields->precision >= 0) && ((size_t)fields->precision < len))
		len = (size_t)fields->precision;
	if (!(fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, len);
	cnt += write(1, str, len);
	if ((fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, len);
	return (cnt);
}
