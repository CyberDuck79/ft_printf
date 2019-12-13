/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:04:04 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/11 14:30:40 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../ft_printf.h"

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putaddr(unsigned long ptr, int prefix);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_itohex(unsigned int n, t_arg *arg);
void	free_args(t_arg *this);
size_t	write_str(const char **str);

#endif
