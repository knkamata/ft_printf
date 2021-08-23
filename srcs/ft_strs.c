#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = write(1, s, ft_strlen(s));
	return (len);
}

static int	ft_check_base(char *base)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(size_t n, char *base, int *cnt)
{
	size_t	baselen;

	if (!(ft_check_base(base)))
		return ;
	baselen = ft_strlen(base);
	if (n >= baselen)
		ft_putnbr_base(n / baselen, base, cnt);
	*cnt += write(1, &base[n % baselen], 1);
	return ;
}
