#include "../ft_printf.h"

int	write_ptr(t_fields *fields)
{
	size_t	tmp;
	int		cnt;

	cnt = 0;
	tmp = (size_t)va_arg(fields->args, void *);
	if (!(fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, ft_numlen_base(tmp, 16) + 2);
	cnt += write(1, "0x", 2);
	ft_putnbr_base(tmp, "0123456789abcdef", &cnt);
	if ((fields->flags & FLAG_MINUS) && (fields->width > 0))
		cnt += write_space(fields, ft_numlen_base(tmp, 16) + 2);
	return (cnt);
}
