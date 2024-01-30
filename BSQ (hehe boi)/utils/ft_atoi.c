/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:59:19 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/01 23:00:00 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	ft_atoi(char *str, unsigned long long *resptr)
{
	unsigned long long	result;
	int					i;
	unsigned long long	new;

	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			return (3);
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		return (2);
	while (str[i] && ft_isdigit(str[i]))
	{
		new = result * 10 + (str[i] - '0');
		if (new < result)
			return (4);
		result = new;
		i++;
	}
	*resptr = result;
	return (str[i] && str[i] != '\0');
}
