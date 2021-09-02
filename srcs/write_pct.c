/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:54:53 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:55:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_pct(t_fields *fields)
{
	int	cnt;

	cnt = 0;
	if (fields->width > 0)
		cnt += write_space(fields, 1);
	cnt += write(1, "%", 1);
	return (cnt);
}
