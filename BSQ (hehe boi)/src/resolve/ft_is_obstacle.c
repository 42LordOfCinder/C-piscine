/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_obstacle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:06:13 by lbouet            #+#    #+#             */
/*   Updated: 2023/08/02 17:17:01 by lbouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	ft_is_obstacle(char c, char *splitted_content)
{
	int	i;

	i = ft_strlen(splitted_content);
	if (c == splitted_content[i - 2])
		return (1);
	return (0);
}
