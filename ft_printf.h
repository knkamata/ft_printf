/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:32:04 by kkamata           #+#    #+#             */
/*   Updated: 2021/09/02 09:01:29 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// +------------------------------------------+ //
//   Headers                                    //
// +------------------------------------------+ //
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// +------------------------------------------+ //
//   Specifiers                                 //
// +------------------------------------------+ //
# define FT_SPECIFIERS "cspdiuxX%"

// +------------------------------------------+ //
//   Type Definition                            //
// +------------------------------------------+ //
typedef enum e_flags
{
	FLAG_SPACE	= 1 << 0,
	FLAG_ZERO	= 1 << 1,
	FLAG_MINUS	= 1 << 2,
	FLAG_PLUS	= 1 << 3,
	FLAG_PERIOD	= 1 << 4,
	FLAG_SHARP	= 1 << 5,
	FLAG_SIGNED	= 1 << 6,
}	t_flags;

typedef struct s_fields
{
	va_list		args;
	int			flags;
	int			width;
	int			precision;
}	t_fields;

// +------------------------------------------+ //
//   Prototypes                                 //
// +------------------------------------------+ //
//      ft_printf                               //
// +------------------------------------------+ //
int		ft_printf(const char *format, ...);

// +------------------------------------------+ //
//      write                                   //
// +------------------------------------------+ //
int		write_format(const char **format, t_fields *fields);
int		write_specifiers(const char **format, t_fields *fields);
int		write_char(t_fields *fields);
int		write_str(t_fields *fields);
int		write_int(t_fields *fields);
int		write_pos_prec(t_fields *fields, size_t len);
int		write_pos_right(t_fields *fields, size_t len);
int		write_pos_left(t_fields *fields, size_t *len);
int		write_neg_prec(t_fields *fields, size_t len);
int		write_neg_left(t_fields *fields, size_t len);
int		write_neg_right(t_fields *fields, size_t len);
int		write_uint(t_fields *fields);
int		write_ptr(t_fields *fields);
int		write_hex(t_fields *fields, int c);
int		write_pct(t_fields *fields);
int		write_sign(t_fields *fields, int c);

// +------------------------------------------+ //
//      write width                             //
// +------------------------------------------+ //
int		write_space(t_fields *fields, size_t len);
int		write_zero(size_t len);

// +------------------------------------------+ //
//      ft                                      //
// +------------------------------------------+ //
size_t	ft_strlen(const char *s);
size_t	ft_numlen(long n);
size_t	ft_numlen_base(size_t n, int base);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_base(size_t n, char *base, int *cnt);

#endif
