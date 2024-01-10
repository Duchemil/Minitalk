/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:55:18 by lduchemi          #+#    #+#             */
/*   Updated: 2023/10/27 14:45:45 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_put_di(int number, int *length);
void	ft_put_hex(unsigned int number, unsigned int base, int *length, char x);
int		ft_putstr(char *str);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
void	ft_put_u(unsigned int number, int *length);
void	ft_put_p(unsigned long number, int *length);
void	ft_ptr(unsigned long number, unsigned long base, int *length, char x);

#endif
