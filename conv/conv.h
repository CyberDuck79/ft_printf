/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:43:43 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/07 11:46:00 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H

# include "../ft_printf.h"

t_conv	unsigned_conv(t_arg *arg, va_list *arg_lst);
t_conv	string_conv(t_arg *arg, va_list *arg_lst);
t_conv	char_conv(t_arg *arg, va_list *arg_lst);
t_conv	integer_conv(t_arg *arg, va_list *arg_lst);
t_conv	pointer_conv(t_arg *arg, va_list *arg_lst);
t_conv	hexa_conv(t_arg *arg, va_list *arg_lst);
t_conv	percent_conv(t_arg *arg, va_list *arg_lst);

#endif
