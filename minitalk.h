/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:54 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/11 17:00:49 by lduchemi         ###   ########.fr       */
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
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char s2);

#endif
