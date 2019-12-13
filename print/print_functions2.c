/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:12:11 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/10 15:12:04 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "../utils/utils.h"

size_t	print_pointer(t_arg *arg)
{
	size_t			len;
	unsigned long	tmp;

	tmp = arg->v.p;
	len = arg->o & POINT ? 1 : 3;
	while (tmp /= 16)
		len++;
	if (arg->o & WIDTH && arg->w > (long)len)
	{
		if (arg->o & MINUS)
			ft_putaddr(arg->v.p, 1);
		write_fill(arg->w - len, arg->o & ZERO);
		if (!(arg->o & MINUS))
			ft_putaddr(arg->v.p, 1);
		return ((size_t)arg->w);
	}
	else if (arg->o & POINT && arg->p > (long)len)
	{
		write_fill(arg->p - len, arg->o & ZERO);
		ft_putaddr(arg->v.p, 0);
		return ((size_t)arg->p);
	}
	else
		ft_putaddr(arg->v.p, 1);
	return (len);
}

size_t	print_unsign(t_arg *arg)
{
	char		*str;
	size_t		len;

	if (arg->o & POINT && !arg->p && !arg->v.u && arg->o & WIDTH)
	{
		write_fill(arg->w, 0);
		return (arg->w);
	}
	else if (arg->o & POINT && !arg->p && !arg->v.u)
		return (0);
	else if (!(str = ft_utoa(arg->v.u)))
		return (0);
	len = ft_strlen(str);
	len = print_options(str, len, arg, 0);
	free((void*)str);
	return (len);
}

size_t	print_hexa(t_arg *arg)
{
	char		*str;
	size_t		len;

	if (arg->o & POINT && !arg->p && !arg->v.u && arg->o & WIDTH)
	{
		write_fill(arg->w, 0);
		return (arg->w);
	}
	else if (arg->o & POINT && !arg->p && !arg->v.u)
		return (0);
	else if (!(str = ft_itohex(arg->v.u, arg)))
		return (0);
	len = ft_strlen(str);
	len = print_options(str, len, arg, 0);
	free((void*)str);
	return (len);
}
