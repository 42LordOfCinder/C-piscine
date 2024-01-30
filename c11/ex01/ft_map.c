/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:59:52 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 22:06:39 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tabres;
	int	i;

	tabres = malloc(sizeof(int) * length);
	if (tabres == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tabres[i] = (*f)(tab[i]);
		i++;
	}
	return (tabres);
}
