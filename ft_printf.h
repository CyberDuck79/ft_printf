/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:41:07 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/09 09:41:18 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** flags index
*/
# define FLAGS "scidpuxX%"

/*
** Explicit error return
*/
typedef enum		e_error
{
	NO_ERROR,
	INVALID
}					t_error;

/*
** flags bit definition
** writed with |= and readed by simple &
*/
typedef enum		e_flags
{
	MINUS = 0b000001,
	ZERO = 0b000010,
	POINT = 0b000100,
	WIDTH = 0b001000,
	WILD = 0b010000,
	MAJ = 0b100000
}					t_flags;

/*
** Supported conversions.
** set as index of conversion and print functions array.
*/
typedef enum		e_conv
{
	STRING,
	CHAR,
	INTEGER,
	DECIMAL,
	POINTER,
	UNSIGN,
	HEXA,
	HEXA_MAJ,
	PERCENT,
	ERROR
}					t_conv;

/*
** p : pointer
** n : integer
** u : unsigned integer
** c : char
** s : string
*/
typedef union		u_value
{
	unsigned long	p;
	int				n;
	unsigned int	u;
	char			c;
	char			*s;
}					t_value;

/*
** n : next arg pointer
** o : options bitfield
** w : arg width
** p : arg precision
** v : arg value
** e : string pointer to end of the conversion
*/
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

/*
** arg_lst : function arguments list
** print : array of print functions indexed by conversion type
** conv : array of conversion functions indexed by conversion type
** Conv functions get the arguments value with the good type.
*/
typedef struct		s_print
{
	va_list			arg_lst;
	size_t			(*print[9])(t_arg*);
	t_conv			(*conv[9])(t_arg*, va_list*);
}					t_print;

t_arg				*new_arg(const char *str, t_print *print);
int					ft_printf(const char *str, ...);

#endif
