/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:22:05 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/24 14:00:08 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc((max - min) * sizeof(*tab));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i + min < max)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i);
}
