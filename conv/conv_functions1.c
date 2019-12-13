/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 09:55:25 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/09 12:44:52 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

t_conv		unsigned_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.u = va_arg(*arg_lst, unsigned int);
	return (UNSIGN);
}

t_conv		string_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.s = va_arg(*arg_lst, char *);
	return (STRING);
}

t_conv		char_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.c = va_arg(*arg_lst, int);
	return (CHAR);
}

t_conv		integer_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.n = va_arg(*arg_lst, int);
	return (INTEGER);
}
