/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:28:01 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/14 13:41:13 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	parse_types(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'p')
		return (ft_putptrnull(va_arg(arg, void *)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_hexnbr(va_arg(arg, unsigned int), 0));
	else if (type == 'X')
		return (ft_hexnbr(va_arg(arg, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += parse_types(str[++i], args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
