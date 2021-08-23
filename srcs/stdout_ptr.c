#include "../ft_printf.h"

int	stdout_ptr(va_list *args)
{
	size_t	tmp;
	int		cnt;

	cnt = 0;
	cnt += write(1, "0x", 2);
	tmp = (size_t)va_arg(*args, void *);
	ft_putnbr_base(tmp, "0123456789abcdef", &cnt);
	return (cnt);
}
