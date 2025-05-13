/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:49:18 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/09 11:49:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CHAR_INT 1
# define NBR_INT 2
# define LOWER 0
# define UPPER 1
# define ADDRESS_HEX 1
# define HEX 0
# define STDOUT 1

//FIXME: Commet type for fix
//NOTE: Comment type for note
//WARN: Comment type for warning

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdint.h>

int		ft_puthex(char *string, int len);
int		ft_putunsigned(unsigned int nbr);
int		ft_printf(const char *format, ...);

#endif
