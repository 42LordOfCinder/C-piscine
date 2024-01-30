/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:27:36 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/31 22:25:22 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_in_charset(str[i], charset)
			&& (ft_is_in_charset(str[i - 1], charset) || i == 0))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_n_word(int n, char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = -1;
	j = 0;
	while ((str[++i] && j < n + 1) || (ft_is_in_charset(str[i], charset)
			&& i == 0 && n == 0))
		if (!ft_is_in_charset(str[i], charset)
			&& (ft_is_in_charset(str[i - 1], charset) || i == 0))
			j++;
	i -= 1;
	len = i;
	while (!ft_is_in_charset(str[len], charset) && str[len])
		len++;
	len -= i;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	*res = 0;
	res = ft_strncpy(res, str + i, len);
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;
	int		i;

	word_count = ft_word_count(str, charset);
	result = malloc(sizeof(char *) * word_count + 1);
	i = 0;
	while (i < word_count)
	{
		result[i] = ft_n_word(i, str, charset);
		i++;
	}
	result[word_count] = 0;
	return (result);
}
