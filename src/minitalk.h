/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:54 by lduchemi          #+#    #+#             */
/*   Updated: 2024/04/26 15:06:38 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_put_di(int number, int *length);
void	ft_put_hex(unsigned int number, unsigned int base, int *length, char x);
int		ft_putstr(char *str);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
void	ft_put_u(unsigned int number, int *length);
void	ft_put_p(unsigned long number, int *length);
void	ft_ptr(unsigned long number, unsigned long base, int *length, char x);
char	*ft_strjoin(char *s1, char s2);

#endif
