#include "../ft_printf.h"

int	stdout_int(va_list *args)
{
	char	*num;
	int		tmp;
	int		cnt;

	tmp = va_arg(*args, int);
	num = ft_itoa(tmp);
	if (!num)
		return (0);
	cnt = ft_putstr(num);
	free(num);
	return (cnt);
}

int	stdout_uint(va_list *args)
{
	char			*num;
	unsigned int	tmp;
	int				cnt;

	tmp = va_arg(*args, unsigned int);
	num = ft_uitoa(tmp);
	if (!num)
		return (0);
	cnt = ft_putstr(num);
	free(num);
	return (cnt);
}
