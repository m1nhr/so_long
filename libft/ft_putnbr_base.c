/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:29:24 by rmarecar          #+#    #+#             */
/*   Updated: 2022/11/28 12:03:22 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	long int	nb;

	nb = nbr;
	if (nb < 0)
		nb = (unsigned int)nb;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base, len);
		ft_putnbr_base(nb % 16, base, len);
	}
	else
		*len += write(1, &base[nb], 1);
}
