/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:54:23 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/20 21:00:36 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils/utils.h"

static t_conv	conv_flags(const char c, const char *flags, t_arg *arg)
{
	size_t	index;

	if (c == 'd')
		return (INTEGER);
	if (c == 'X')
	{
		arg->o |= MAJ;
		return (HEXA);
	}
	index = 0;
	while (flags[index] && c != flags[index])
		index++;
	if (flags[index])
		return ((t_conv)index);
	return (ERROR);
}

static void		options(const char **str, t_arg *arg)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			arg->o |= MINUS;
		else if (**str == '0')
			arg->o |= ZERO;
		(*str)++;
	}
	if (arg->o & MINUS && arg->o & ZERO)
		arg->o &= ~ZERO;
}

static void		width(const char **str, t_arg *arg, va_list *arg_lst)
{
	if (**str > 47 && **str < 58)
	{
		arg->o |= WIDTH;
		arg->w = ft_atoi(*str);
		while (**str > 47 && **str < 58)
			(*str)++;
	}
	else if (**str == '*')
	{
		arg->o |= WIDTH;
		arg->w = (long)va_arg(*arg_lst, int);
		if (arg->w < 0)
		{
			arg->w = -arg->w;
			arg->o |= MINUS;
			if (arg->o & ZERO)
				arg->o &= ~ZERO;
		}
		(*str)++;
	}
}

static void		precision(const char **str, t_arg *arg, va_list *arg_lst)
{
	if (**str == '.')
	{
		(*str)++;
		arg->o |= POINT;
		if (**str == '*')
		{
			arg->p = (long)va_arg(*arg_lst, int);
			if (arg->p < 0)
				arg->o &= ~POINT;
			(*str)++;
		}
		else if (**str > 47 && **str < 58)
		{
			arg->p = ft_atoi(*str);
			while (**str > 47 && **str < 58)
				(*str)++;
		}
		else
			arg->p = 0;
	}
}

t_arg			*new_arg(const char *str, t_print *print)
{
	t_arg		*new;
	t_conv		conv_flag;

	if (!(new = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	new->o = 0;
	new->n = NULL;
	options(&str, new);
	width(&str, new, &print->arg_lst);
	precision(&str, new, &print->arg_lst);
	if ((conv_flag = conv_flags(*str, FLAGS, new)) == ERROR)
	{
		free(new);
		return (NULL);
	}
	new->e = str + 1;
	conv_flag = print->conv[conv_flag](new, &print->arg_lst);
	new->print = print->print[conv_flag];
	return (new);
}
