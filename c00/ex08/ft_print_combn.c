/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:39:02 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/14 11:38:01 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rec_combn(int n, int depth, char *tab)
{
	if (depth != 0)
		tab[depth] = tab[depth - 1] + 1;
	else
		tab[depth] = '0';
	while (tab[depth] <= '9' - n + depth + 1)
	{
		if (depth == n - 1)
		{
			write(1, tab, n);
			if (tab[0] != '9' - n + 1)
				write(1, ", ", 2);
		}
		else
			ft_rec_combn(n, depth + 1, tab);
		tab[depth]++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[9];

	ft_rec_combn(n, 0, tab);
}
