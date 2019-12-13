/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:00:05 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/10 11:28:29 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	printaddr(unsigned long ptr)
{
	if (ptr < 10)
		ft_putchar((char)(ptr + '0'));
	else if (ptr < 16)
		ft_putchar((char)(ptr + 87));
	else
	{
		printaddr(ptr / 16);
		printaddr(ptr % 16);
	}
}

void		ft_putaddr(unsigned long ptr, int prefix)
{
	if (prefix)
		write(1, "0x", 2);
	printaddr(ptr);
}
