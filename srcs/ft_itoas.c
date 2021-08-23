#include "../ft_printf.h"

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	long	nn;
	char	*dst;

	nn = n;
	len = ft_numlen(nn);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	if (nn == 0)
		dst[0] = '0';
	dst[len] = '\0';
	len--;
	while (nn > 0)
	{
		dst[len] = nn % 10 + '0';
		nn /= 10;
		len--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nn;
	char	*dst;

	nn = n;
	len = ft_numlen(nn);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	if (nn == 0)
		dst[0] = '0';
	if (nn < 0)
	{
		dst[0] = '-';
		nn *= -1;
	}
	dst[len] = '\0';
	len--;
	while (nn > 0)
	{
		dst[len] = nn % 10 + '0';
		nn /= 10;
		len--;
	}
	return (dst);
}
