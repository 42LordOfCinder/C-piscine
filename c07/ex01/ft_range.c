/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:17:21 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/20 19:04:04 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	tab = (int *)malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i + min < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
