/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:08:17 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/17 11:28:28 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_rec(int nb);

void	ft_putnbr(int nb)
{
	if (nb != -2147483648)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_putnbr_rec(nb);
	}
	else
		write(1, "-2147483648", 11);
}

void	ft_putnbr_rec(int nb)
{
	char	i;

	i = nb % 10 + 48;
	if (nb >= 10)
		ft_putnbr_rec(nb / 10);
	write(1, &i, 1);
}
