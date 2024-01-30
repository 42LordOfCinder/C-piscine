/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:44:28 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/23 17:07:26 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(int *tab, int size)
{
	int	i;

	if (size == 0)
		return (1);
	i = size - 1;
	while (i >= 0)
	{
		if (tab[i] == tab[size] || tab[i] == (tab[size] + (size - i))
			|| tab[i] == (tab[size] - (size - i)))
			return (0);
		i--;
	}
	return (1);
}

void	ft_display_tab(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_rec_ten_queens(int *tab, int depth, int *total_ptr)
{
	int	i;

	if (depth == 10)
	{
		ft_display_tab(tab);
		*total_ptr = *total_ptr + 1;
	}
	i = 0;
	while (i <= 9)
	{
		tab[depth] = i;
		if (ft_check(tab, depth))
			ft_rec_ten_queens(tab, depth + 1, total_ptr);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[11];
	int	total;
	int	*total_ptr;

	total = 0;
	total_ptr = &total;
	ft_rec_ten_queens(tab, 0, total_ptr);
	return (total);
}
