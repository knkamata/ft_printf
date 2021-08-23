#include "../ft_printf.h"

int	stdout_hex(va_list *args, int c)
{
	unsigned int	tmp;
	int				cnt;

	cnt = 0;
	tmp = (unsigned int)va_arg(*args, unsigned int);
	if (c == 'x')
		ft_putnbr_base(tmp, "0123456789abcdef", &cnt);
	if (c == 'X')
		ft_putnbr_base(tmp, "0123456789ABCDEF", &cnt);
	return (cnt);
}
