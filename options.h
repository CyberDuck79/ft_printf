/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:38:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/09 09:39:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

#include "ft_printf.h"

void	write_fill(size_t len, int zero);
size_t	ft_width(char *str, size_t len, t_arg *arg, int neg);
size_t	print_options(char *str, size_t len, t_arg *arg, int neg);

#endif
