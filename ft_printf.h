/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:41:07 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/09 16:05:09 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FLAGS "scipux%"

typedef enum		e_error
{
	NO_ERROR,
	INVALID
}					t_error;

typedef enum		e_flags
{
	MINUS = 1,
	ZERO = 2,
	POINT = 4,
	WIDTH = 8,
	WILD = 16,
	MAJ = 32
}					t_flags;

typedef enum		e_conv
{
	STRING,
	CHAR,
	INTEGER,
	POINTER,
	UNSIGN,
	HEXA,
	PERCENT,
	ERROR
}					t_conv;

typedef union		u_value
{
	unsigned long	p;
	int				n;
	unsigned int	u;
	char			c;
	char			*s;
}					t_value;

typedef struct		s_arg
{
	struct s_arg	*n;
	char			o;
	long			w;
	long			p;
	t_value			v;
	const char		*e;
	size_t			(*print)(struct s_arg *this);
}					t_arg;

typedef struct		s_print
{
	va_list			arg_lst;
	size_t			(*print[6])(t_arg*);
	t_conv			(*conv[7])(t_arg*, va_list*);
}					t_print;

void				write_fill(size_t len, int zero);
size_t				ft_width(char *str, size_t len, t_arg *arg, int neg);
size_t				print_options(char *str, size_t len, t_arg *arg, int neg);
t_arg				*new_arg(const char *str, t_print *print);
int					ft_printf(const char *str, ...);

#endif
