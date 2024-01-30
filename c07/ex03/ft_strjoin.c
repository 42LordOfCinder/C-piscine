/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:55:16 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/27 01:30:49 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_len_max(int size, char **strs, int sep_size)
{
	int	i;
	int	len_max;

	len_max = sep_size * -1;
	i = 0;
	while (i < size)
	{
		len_max += ft_strlen(strs[i]) + sep_size;
		i++;
	}
	if (len_max < 0)
		return (0);
	return (len_max);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		len_max;

	if (size == 0 || !sep || !strs)
	{
		result = (char *)malloc(1);
		result[0] = 0;
		return (result);
	}
	len_max = ft_len_max(size, strs, ft_strlen(sep));
	result = malloc(sizeof(char) * (len_max + 1));
	if (result == NULL)
		return (0);
	*result = 0;
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i < size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	result[len_max] = '\0';
	return (result);
}
