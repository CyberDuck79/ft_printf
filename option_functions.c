/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:52:03 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/09 09:43:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

void			write_fill(size_t len, int zero)
{
	char	filler;

	filler = zero ? '0' : ' ';
	while (len--)
		write(1, &filler, 1);
}

static size_t	ft_override(char *str, size_t len, t_arg *arg, int neg)
{
	if (arg->o & MINUS)
	{
		if (neg)
			write(1, "-", 1);
		write_fill(arg->p - len, 1);
		write(1, str, len);
		write_fill(arg->w - arg->p - neg, 0);
	}
	else
	{
		write_fill(arg->w - arg->p - neg, 0);
		if (neg)
			write(1, "-", 1);
		write_fill(arg->p - len, 1);
		write(1, str, len);
	}
	return (neg ? arg->w - 1 : arg->w);
}

static size_t	ft_precision(char *str, size_t len, t_arg *arg, int neg)
{
	if (neg)
		write(1, "-", 1);
	write_fill(arg->p - len, 1);
	write(1, str, len);
	return (arg->p);
}

size_t			ft_width(char *str, size_t len, t_arg *arg, int neg)
{
	if (arg->o & MINUS && neg)
		write(1, "-", 1);
	if (arg->o & MINUS)
		write(1, str, len);
	if (!(arg->o & MINUS) && neg && arg->o & ZERO && !(arg->o & POINT))
		write(1, "-", 1);
	write_fill(arg->w - len - neg, arg->o & ZERO && !(arg->o & POINT));
	if (!(arg->o & MINUS) && neg && (arg->o & POINT || !(arg->o & ZERO)))
		write(1, "-", 1);
	if (!(arg->o & MINUS))
		write(1, str, len);
	return (neg ? arg->w - 1 : arg->w);
}

size_t			print_options(char *str, size_t len, t_arg *arg, int neg)
{
	if (arg->o & WIDTH && arg->w > (long)len
	&& arg->o & POINT && arg->p > (long)len && arg->w > arg->p)
		return (ft_override(str, len, arg, neg));
	else if (arg->o & POINT && arg->p > (long)len)
		return (ft_precision(str, len, arg, neg));
	else if (arg->o & WIDTH && arg->w > (long)len)
		return (ft_width(str, len, arg, neg));
	else if (neg)
		write(1, "-", 1);
	return (write(1, str, len));
}
