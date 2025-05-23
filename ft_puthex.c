/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:25 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/07 15:53:19 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char *string, int len)
{
	int	temp_len;

	temp_len = len;
	while (temp_len > 0)
	{
		write(1, &string[temp_len - 1], 1);
		temp_len--;
	}
	return (len);
}
