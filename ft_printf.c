/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:16:27 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/11 14:30:10 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print/print.h"
#include "conv/conv.h"
#include "utils/utils.h"

static void		ft_assign_print(t_print *print)
{
	print->print[STRING] = print_str;
	print->print[CHAR] = print_char;
	print->print[INTEGER] = print_nbr;
	print->print[POINTER] = print_pointer;
	print->print[UNSIGN] = print_unsign;
	print->print[HEXA] = print_hexa;
}

static void		ft_assign_conv(t_print *print)
{
	print->conv[STRING] = string_conv;
	print->conv[CHAR] = char_conv;
	print->conv[INTEGER] = integer_conv;
	print->conv[POINTER] = pointer_conv;
	print->conv[UNSIGN] = unsigned_conv;
	print->conv[HEXA] = hexa_conv;
	print->conv[PERCENT] = percent_conv;
}

static t_error	ft_parse(const char *str, t_arg **args, t_print *print)
{
	while (*str && *str != '%')
		str++;
	if (!*str)
		return (NO_ERROR);
	if (!(*args = new_arg(str + 1, print)))
		return (INVALID);
	return (ft_parse((*args)->e, &(*args)->n, print));
}

static int		ft_print(const char *str, t_arg *args)
{
	size_t	len;
	t_arg	*release;

	len = 0;
	while (*str)
	{
		len += write_str(&str);
		if (*str)
		{
			len += args->print(args);
			str = args->e;
			release = args;
			args = args->n;
			free(release);
		}
	}
	return ((int)len);
}

int				ft_printf(const char *str, ...)
{
	t_arg	*args;
	t_print	print;

	args = NULL;
	va_start(print.arg_lst, str);
	ft_assign_print(&print);
	ft_assign_conv(&print);
	if (ft_parse(str, &args, &print))
	{
		if (args)
			free_args(args);
		return (-1);
	}
	va_end(print.arg_lst);
	return (ft_print(str, args));
}
