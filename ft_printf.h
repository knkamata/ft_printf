#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/***** Headers *****/
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/***** Prototypes *****/
/*** main ***/
int		ft_printf(const char *format, ...);

/*** stdout ***/
int		stdout_char(va_list *args);
int		stdout_str(va_list *args);
int		stdout_int(va_list *args);
int		stdout_uint(va_list *args);
int		stdout_ptr(va_list *args);
int		stdout_hex(va_list *args, int c);

/*** fts ***/
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_putstr(char *s);
void	ft_putnbr_base(size_t n, char *base, int *cnt);

#endif
