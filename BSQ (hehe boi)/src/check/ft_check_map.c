/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:11:10 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 14:52:05 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	ft_check_occ(char *charset, char **splitted_content)
{
	int		i;
	int		j;
	char	*charset_cpy;

	charset_cpy = ft_strdup(charset);
	charset_cpy[2] = 0;
	i = 0;
	while (splitted_content[i])
	{
		j = 0;
		while (splitted_content[i][j])
		{
			if (!ft_is_in_charset(splitted_content[i][j], charset_cpy))
			{
				free(charset_cpy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(charset_cpy);
	return (1);
}

int	ft_handle_linebreaks(char *content)
{
	int	i;
	int	cmpt;

	i = 0;
	cmpt = 0;
	while (i < ft_strlen(content))
	{
		if (content[i] == '\n')
		{
			if (content[i + 1] == '\n')
				return (0);
			cmpt++;
		}
		i++;
	}
	return (cmpt);
}

int	ft_free_charset_and_ptr(char *charset, char **charset_ptr)
{
	free(charset);
	free(charset_ptr);
	return (0);
}

int	ft_check_map(char *content, char **splitted_content)
{
	int		line_count;
	int		i;
	int		line_size;
	char	**charset_ptr;
	int		linebreak_count;

	charset_ptr = malloc(sizeof(char *));
	*charset_ptr = 0;
	line_count = ft_check_header(splitted_content[0], charset_ptr);
	if (line_count == 0 || ft_strtablen(splitted_content) - 1 != line_count)
		return (ft_free_charset_and_ptr(*charset_ptr, charset_ptr));
	i = 1;
	line_size = ft_strlen(splitted_content[1]);
	while (splitted_content[++i])
		if (ft_strlen(splitted_content[i]) != line_size)
			return (ft_free_charset_and_ptr(*charset_ptr, charset_ptr));
	if (!ft_check_occ(*charset_ptr, splitted_content + 1))
		return (ft_free_charset_and_ptr(*charset_ptr, charset_ptr));
	ft_free_charset_and_ptr(*charset_ptr, charset_ptr);
	linebreak_count = ft_handle_linebreaks(content);
	if (!linebreak_count || linebreak_count != line_count + 1)
		return (0);
	return (1);
}
