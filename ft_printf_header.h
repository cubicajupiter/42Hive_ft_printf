/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:01:50 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/07 15:50:11 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H

#define CHAR_INT 1
#define NBR_INT 2
#define LOWER 0
#define UPPER 1
#define ADDRESS_HEX 0
#define HEX 1

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>
#include <stdint.h>

void ft_puthex();
void ft_putunsigned(unsigned int nbr);

#endif
