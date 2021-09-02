/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:08:55 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:08:56 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_sign(t_fields *fields, int c)
{
	int	cnt;

	cnt = write(1, &c, 1);
	fields->flags |= FLAG_SIGNED;
	return (cnt);
}

static int	write_int_neg(t_fields *fields, int tmp)
{
	int				cnt;
	char			*num;
	unsigned int	n;
	size_t			len;

	n = tmp * (-1);
	num = ft_uitoa(n);
	if (!num)
		return (0);
	cnt = 0;
	len = ft_strlen(num);
	if (fields->flags & FLAG_PERIOD)
		cnt += write_neg_prec(fields, len);
	len++;
	if (!(fields->flags & FLAG_MINUS))
		cnt += write_neg_left(fields, len);
	if (!(fields->flags & FLAG_SIGNED))
		cnt += write_sign(fields, '-');
	cnt += write(1, num, ft_strlen(num));
	if (fields->flags & FLAG_MINUS)
		cnt += write_neg_right(fields, len);
	free(num);
	return (cnt);
}

static int	write_int_pos(t_fields *fields, int tmp)
{
	int		cnt;
	char	*num;
	size_t	len;

	num = ft_itoa(tmp);
	if (!num)
		return (0);
	cnt = 0;
	len = ft_strlen(num);
	if (fields->flags & FLAG_PERIOD)
		cnt += write_pos_prec(fields, len);
	if (!(fields->flags & FLAG_MINUS))
		cnt += write_pos_left(fields, &len);
	if (fields->flags & FLAG_PLUS && !(fields->flags & FLAG_SIGNED))
		cnt += write(1, "+", 1);
	if (!(fields->flags & FLAG_PLUS) \
			&& (fields->flags & FLAG_SPACE) && !(fields->flags & FLAG_SIGNED))
		cnt += write(1, " ", 1);
	cnt += write(1, num, ft_strlen(num));
	if (fields->flags & FLAG_MINUS)
		cnt += write_pos_right(fields, len);
	free(num);
	return (cnt);
}

int	write_int(t_fields *fields)
{
	int		tmp;
	int		cnt;

	cnt = 0;
	tmp = va_arg(fields->args, int);
	if (tmp >= 0)
		cnt += write_int_pos(fields, tmp);
	if (tmp < 0)
		cnt += write_int_neg(fields, tmp);
	return (cnt);
}
