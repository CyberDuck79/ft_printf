/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:58:20 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/10 15:52:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_size(int n)
{
	size_t	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	size_t			size;

	size = ft_size(n);
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size] = '\0';
	if (!n)
		*str = '0';
	nbr = n < 0 ? -n : n;
	while (nbr)
	{
		size--;
		str[size] = (char)((nbr % 10) + 48);
		nbr /= 10;
	}
	return (str);
}
