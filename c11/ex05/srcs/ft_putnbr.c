/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:08:17 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/03 16:54:38 by gmassoni         ###   ########.fr       */
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
		write(1, "\n", 1);
	}
	else
		write(1, "-2147483648\n", 12);
}

void	ft_putnbr_rec(int nb)
{
	char	i;

	i = nb % 10 + 48;
	if (nb >= 10)
		ft_putnbr_rec(nb / 10);
	write(1, &i, 1);
}
