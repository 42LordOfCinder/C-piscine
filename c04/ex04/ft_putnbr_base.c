/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:15:41 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/23 16:55:23 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base_rec(unsigned int nb, unsigned int size, char *base)
{
	int	i;

	i = nb % size;
	if (nb >= size)
		ft_putnbr_base_rec(nb / size, size, base);
	write(1, &base[i], 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	ft_error_handler(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	if (ft_error_handler(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_putnbr_base_rec((unsigned int) nb, ft_strlen(base), base);
	}
}
