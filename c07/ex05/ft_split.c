/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:44:51 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/27 11:16:20 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_in_charset(str[i], charset)
			&& (ft_is_in_charset(str[i - 1], charset) || i == 0))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (i < src_len && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_n_word(int i, char *str, char *charset)
{
	char	*result;
	int		j;
	int		k;
	int		len;

	j = -1;
	k = 0;
	len = 0;
	while ((str[++j] && k < i + 1) || (ft_is_in_charset(str[j], charset)
			&& i == 0))
		if (!ft_is_in_charset(str[j], charset)
			&& (ft_is_in_charset(str[j - 1], charset) || j == 0))
			k++;
	j -= 1;
	if (i == 0 && ft_is_in_charset(str[j], charset))
		j -= 1;
	while (!ft_is_in_charset(str[j + len], charset)
		&& str[j + len])
		len++;
	result = (char *)malloc(sizeof(char) * len);
	if (result == NULL)
		return (0);
	ft_strncpy(result, str + j, len);
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**result;
	int		i;

	word_count = ft_word_count(str, charset);
	result = (char **)malloc(sizeof(char *) * word_count + 1);
	if (result == NULL)
		return (0);
	i = 0;
	while (i < word_count)
	{
		result[i] = ft_n_word(i, str, charset);
		i++;
	}
	result[word_count] = 0;
	return (result);
}
