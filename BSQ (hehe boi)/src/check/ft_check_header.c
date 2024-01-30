/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:17:16 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 14:43:42 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	ft_check_nbrs(char *str)
{
	int	i;
	int	*ptr;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	ptr = &i;
	ft_atoi(str, (unsigned long long *) ptr);
	return (i);
}

int	ft_check_charset(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_free_elts(char *nbrs, char *charset)
{
	free(nbrs);
	free(charset);
	return (0);
}

int	ft_check_header(char *str, char **ptr)
{
	int		len;
	int		i;
	char	*nbrs;
	char	*charset;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	i = -1;
	nbrs = malloc(sizeof(char) * (len - 3) + 1);
	while (++i < len - 3)
		nbrs[i] = str[i];
	nbrs[i] = 0;
	charset = malloc(sizeof(char) * (3 + 1));
	i = -1;
	while (++i < 3)
		charset[i] = str[(len - 3) + i];
	charset[i] = 0;
	i = ft_check_nbrs(nbrs);
	if (!i || !ft_check_charset(charset))
		return (ft_free_elts(nbrs, charset));
	*ptr = ft_strdup(charset);
	ft_free_elts(nbrs, charset);
	return (i);
}
