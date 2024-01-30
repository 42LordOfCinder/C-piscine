/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:27:26 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 19:29:17 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

void	ft_display(char **sc)
{
	int	i;

	i = 1;
	while (sc[i])
	{
		ft_putstr(sc[i]);
		ft_putstr("\n");
		i++;
	}
}
