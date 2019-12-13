/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:58:52 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/09 12:43:16 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		index;
	int		neg;
	long	res;

	index = 0;
	res = 0;
	while (str[index] == 32 || (str[index] > 8 && str[index] < 14))
		index++;
	neg = (str[index] == '-') ? 1 : 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (ft_isdigit(str[index]) && res < 2147483649)
	{
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	if ((neg && res > 2147483648) || (!neg && res > 2147483647))
		return (neg ? 0 : -1);
	return ((int)(neg ? -res : res));
}
