/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:52:51 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/10 15:53:10 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_usize(unsigned int n)
{
	size_t	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_utoa(unsigned int n)
{
	char			*str;
	size_t			size;

	size = ft_usize(n);
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size] = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		size--;
		str[size] = (char)((n % 10) + 48);
		n /= 10;
	}
	return (str);
}
