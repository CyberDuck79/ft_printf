/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:08:13 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/11 14:30:42 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
		index++;
	return (index);
}

size_t	write_str(const char **str)
{
	size_t	len;

	len = 0;
	while ((*str)[len] && (*str)[len] != '%')
		len++;
	write(1, *str, len);
	*str += len;
	return (len);
}

void	free_args(t_arg *this)
{
	t_arg	*tmp;

	while (this)
	{
		tmp = this;
		this = this->n;
		free(tmp);
	}
}
