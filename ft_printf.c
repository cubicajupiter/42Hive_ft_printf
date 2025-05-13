/* ************************************************************************** */
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

#include "ft_printf.h"

static int	ft_hex(uint64_t nbr, const char *base, int address);
static int	ft_str(char *str);
static int	ft_int(int var, int signed_integer);
static int	ft_designator(va_list *args, char specifier);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			count += ft_designator(&args, *++format);
			format++;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

static int	ft_hex(uint64_t nbr, const char *base, int address)
{
	int			len;
	char		string[18];
	char		digit;

	len = 0;
	if (!nbr && !address)
		string[len++] = '0';
	if (!address)
		nbr = (uint32_t) nbr;
	while (nbr > 0)
	{
		digit = base[nbr % ft_strlen(base)];
		string[len++] = digit;
		nbr /= 16;
	}
	if (address && len)
	{
		string[len++] = 'x';
		string[len++] = '0';
	}
	return (ft_puthex(string, len));
}

static int	ft_str(char *str)
{
	int	len;

	if (!str)
	{
		len = 6;
		ft_putstr_fd("(null)", STDOUT);
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, STDOUT);
	}
	return (len);
}

static int	ft_int(int var, int signed_integer)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = NULL;
	if (signed_integer == NBR_INT)
	{
		nbr = ft_itoa(var);
		if (!nbr)
			return (0);
		ft_putstr_fd(nbr, STDOUT);
		len = ft_strlen(nbr);
		free(nbr);
	}
	else if (signed_integer == CHAR_INT)
	{
		ft_putchar_fd(var, STDOUT);
		len = 1;
	}
	return (len);
}

static int	ft_designator(va_list *args, char specifier)
{
	uintptr_t	address_hex;

	if (specifier == 's')
		return (ft_str(va_arg(*args, char *)));
	else if (specifier == 'p')
	{
		address_hex = (uintptr_t)va_arg(*args, void *);
		if (address_hex != 0)
			return (ft_hex(address_hex, "0123456789abcdef", ADDRESS_HEX));
		write(1, "(nil)", 5);
		return (5);
	}
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (specifier == 'c')
		return (ft_int(va_arg(*args, int), CHAR_INT));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_int(va_arg(*args, int), NBR_INT));
	else if (specifier == 'x')
		return (ft_hex(va_arg(*args, int), "0123456789abcdef", HEX));
	else if (specifier == 'X')
		return (ft_hex(va_arg(*args, int), "0123456789ABCDEF", HEX));
	else if (specifier == '%')
		return (ft_int('%', CHAR_INT));
	return (0);
}
