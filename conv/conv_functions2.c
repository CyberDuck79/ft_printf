/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:13:10 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/09 12:45:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

t_conv		pointer_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.p = va_arg(*arg_lst, unsigned long);
	return (POINTER);
}

t_conv		hexa_conv(t_arg *arg, va_list *arg_lst)
{
	arg->v.u = va_arg(*arg_lst, unsigned int);
	return (HEXA);
}

t_conv		percent_conv(t_arg *arg, va_list *arg_lst)
{
	(void)arg_lst;
	arg->v.c = '%';
	return (CHAR);
}
