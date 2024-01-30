/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:55:47 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/13 17:39:20 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				k = tab[i];
				l = tab[j];
				tab[i] = l;
				tab[j] = k;
			}
			j++;
		}
		i++;
	}
}
