/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:52:45 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/10 15:12:21 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "../utils/utils.h"

size_t	print_str(t_arg *arg)
{
	size_t	len;

	if (!arg->v.s && arg->o & POINT && !arg->p)
		arg->v.s = "";
	else if (!arg->v.s)
		arg->v.s = "(null)";
	len = ft_strlen(arg->v.s);
	if (arg->o & WIDTH && arg->w >= arg->p && arg->o & POINT)
	{
		arg->p = arg->p < (long)len ? arg->p : (long)len;
		if (!(arg->o & MINUS))
			write_fill(arg->w - arg->p, arg->o & ZERO);
		write(1, arg->v.s, arg->p);
		if (arg->o & MINUS)
			write_fill(arg->w - arg->p, arg->o & ZERO);
		return ((size_t)arg->w);
	}
	else if (arg->o & WIDTH && arg->w >= (long)len)
		return (ft_width(arg->v.s, len, arg, 0));
	else if (arg->o & POINT && arg->p < (long)len)
		return (write(1, arg->v.s, arg->p));
	return (write(1, arg->v.s, len));
}

size_t	print_char(t_arg *arg)
{
	if (arg->o & WIDTH && arg->w > 1)
	{
		if (!(arg->o & MINUS))
			write_fill(arg->w - 1, arg->o & ZERO);
		write(1, &arg->v.c, 1);
		if (arg->o & MINUS)
			write_fill(arg->w - 1, arg->o & ZERO);
		return (arg->w);
	}
	return (write(1, &arg->v.c, 1));
}

size_t	print_nbr(t_arg *arg)
{
	char		*str;
	size_t		len;

	if (arg->o & POINT && !arg->p && !arg->v.n && arg->o & WIDTH)
	{
		write_fill(arg->w, 0);
		return (arg->w);
	}
	else if (arg->o & POINT && !arg->p && !arg->v.n)
		return (0);
	else if (!(str = ft_itoa(arg->v.n)))
		return (0);
	len = ft_strlen(str);
	len = print_options(str, len, arg, arg->v.n < 0 ? 1 : 0);
	free((void*)str);
	return (arg->v.n < 0 ? len + 1 : len);
}
