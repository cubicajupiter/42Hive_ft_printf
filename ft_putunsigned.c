/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:47:21 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/07 16:30:34 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	char	buffer[10];
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (j <= i)
	{
		write(1, &buffer[i - j], 1);
		j++;
	}
	return (i);
}
