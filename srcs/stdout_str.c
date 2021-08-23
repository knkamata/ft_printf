#include "../ft_printf.h"

int	stdout_char(va_list *args)
{
	char	c;
	int		cnt;

	c = va_arg(*args, int);
	cnt = write(1, &c, 1);
	return (cnt);
}

int	stdout_str(va_list *args)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	cnt = ft_putstr(str);
	return (cnt);
}
