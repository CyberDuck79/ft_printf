/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:01:00 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/09 12:43:32 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_size_hex(unsigned int n)
{
	size_t	size;

	size = 1;
	while (n /= 16)
		size++;
	return (size);
}

static char		ft_tohex(unsigned int nbr, t_arg *arg)
{
	if (nbr % 16 > 9)
	{
		if (arg->o & MAJ)
			return ((char)((nbr % 16) + 55));
		else
			return ((char)((nbr % 16) + 87));
	}
	return ((char)((nbr % 16) + 48));
}

char			*ft_itohex(unsigned int n, t_arg *arg)
{
	char			*str;
	size_t			size;

	size = ft_size_hex(n);
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size] = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		size--;
		str[size] = ft_tohex(n, arg);
		n /= 16;
	}
	return (str);
}
