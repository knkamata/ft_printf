/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:08:18 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:08:19 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_space(t_fields *fields, size_t len)
{
	int	cnt;

	cnt = 0;
	if (fields->width > 0)
	{
		while ((size_t)fields->width > len)
		{
			cnt += write(1, " ", 1);
			fields->width -= 1;
		}
	}
	return (cnt);
}

int	write_zero(size_t len)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (i < len)
	{
		cnt += write(1, "0", 1);
		i++;
	}
	return (cnt);
}
