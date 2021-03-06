/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:41:38 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/09 09:40:15 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../options.h"

size_t	print_str(t_arg *arg);
size_t	print_char(t_arg *arg);
size_t	print_nbr(t_arg *arg);
size_t	print_pointer(t_arg *arg);
size_t	print_unsign(t_arg *arg);
size_t	print_hexa(t_arg *arg);

#endif
