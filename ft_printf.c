r* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:03:33 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/05 17:02:03 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static int	ft_hex(uint64_t nbr, int upper, int mem)
{
	int			len;
	int			n;
	const char	*base;
	char		string[16]; //if 0x needs to be part of string, make this 18
	char		digit;

	len = 0;
	base = "0123456789abcdef";
	while (nbr > 0)
	{
		n = nbr % 16;
		digit = base[n];
		if (upper && ft_isalpha(digit))
			digit = ft_toupper(digit);
		string[len] = digit;
		nbr = nbr / 16;
		len++;
	}
	if (mem)
	{
		write(1, "0x", 2); //might have to insert these in string if len fucked up otherwise
		len += 2; //now this might fuck up len for    ft_puthex(); if mem   so deal with it.
	}
	ft_puthex(string, len);
	return (len);
}

static int	ft_str(void *var, int len)
{
	int	len;

	len = ft_strlen(var);
	ft_putstr_fd(var, 1);
	return (len);
}

static int	ft_int(int var, int signed_integer)
{
	int		len;
	char	*str;

	len = 0
	str = NULL;
	if (signed_integer == NUMBER_INT)
	{
		str = ft_itoa(var);
		if (!str)
			return (NULL);
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		free(str);
	}
	else if (signed_integer == CHAR_INT)
	{
		ft_putchar_fd((int)var);
		len = 1;
	}
	return (len);
}

static int	ft_designator(va_list *arg_ptr, char specifier)
{
	if (specifier == 's')
		return (ft_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_hex((uintptr_t)va_arg(args, void *), LOWER, ADDRESS_HEX));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if	(specifier == 'c')
		return (ft_int(va_arg(args, int), CHAR_INT));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_int(va_arg(args, int), NBR_INT));
	else if (specifier == 'x')
		return (ft_hex(va_arg(args, int), LOWER, HEX));
	else if (specifier == 'X')
		return (ft_hex(va_arg(args, int), UPPER,  HEX));
	else if (specifier == '%')
	{
		ft_putchar('%', 1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	*ap;
	int		count;

	count = 0;
	if (!format || *format == '\0')
		return (count);
	va_start(args, format);
	*ap = &args;
	while(*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1))) //error handling for invalid specifiers?
		{
			count += ft_designate(ap, *++format);
			format++;
		}
		else if (*format)
		{
			count++;
			write(1, format++, 1);
		}
	}
	va_end(args);
	return (count);
}
