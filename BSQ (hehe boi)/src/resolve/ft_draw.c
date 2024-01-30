/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:26:40 by lbouet            #+#    #+#             */
/*   Updated: 2023/08/02 20:13:17 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

void	ft_draw(char **sc, t_coord maxcoord, int size)
{
	char	full;
	int		j;
	int		i;

	full = sc[0][ft_strlen(sc[0]) - 1];
	if (size == 1)
		sc[maxcoord.y][maxcoord.x] = full;
	else
	{
		j = maxcoord.y;
		while (j >= maxcoord.y - size)
		{
			i = maxcoord.x;
			while (i >= maxcoord.x - size)
			{
				sc[j][i] = full;
				i--;
			}
			j--;
		}
	}
	ft_display(sc);
}
