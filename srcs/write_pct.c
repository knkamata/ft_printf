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
