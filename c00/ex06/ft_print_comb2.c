/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:41:35 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/13 21:12:03 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nb(int i, int j)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = (i / 10) + 48;
	b = (i % 10) + 48;
	c = (j / 10) + 48;
	d = (j % 10) + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_nb(i, j);
			if (i != 98)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
