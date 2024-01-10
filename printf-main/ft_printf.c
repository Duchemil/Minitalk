/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:55:07 by lduchemi          #+#    #+#             */
/*   Updated: 2023/10/27 14:43:39 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int i)
{
	return (write(1, &i, 1));
}

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		ft_put_di(va_arg(args, int), &length);
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'u')
		ft_put_u(va_arg(args, long), &length);
	else if (format == 'x')
		ft_put_hex(va_arg(args, int), 16, &length, 'x');
	else if (format == 'X')
		ft_put_hex(va_arg(args, int), 16, &length, 'X');
	else if (format == 'p')
		ft_put_p(va_arg(args, unsigned long long), &length);
	else if (format == '%')
		length += write(1, "%", 1);
	return (length);
}

int	ft_printf(const char *s, ...)
{
	size_t	len;
	int		i;
	va_list	list_args;

	va_start(list_args, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			len += ft_putchar(s[i]);
		else
			len += ft_format(list_args, s[++i]);
		i++;
	}
	va_end(list_args);
	return (len);
}
