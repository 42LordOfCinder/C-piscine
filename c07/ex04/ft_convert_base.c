/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:26:48 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/25 19:33:05 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_nbr_to_base(int nb, char *base);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_error_handler(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	summ;

	if (ft_error_handler(base))
	{
		i = 0;
		sign = 1;
		summ = 0;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (ft_is_in_base(str[i], base) > -1)
		{
			summ = (summ * ft_strlen(base)) + ft_is_in_base(str[i], base);
			i++;
		}
		return (summ * sign);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 40);
	if (result == NULL)
		return (0);
	if (ft_error_handler(base_from) && ft_error_handler(base_to))
	{
		result = ft_nbr_to_base(ft_atoi_base(nbr, base_from), base_to);
		return (result);
	}
	return (NULL);
}
