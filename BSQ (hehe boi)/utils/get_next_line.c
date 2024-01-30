/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:08:33 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 02:31:20 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

char	*get_next_line(int fd)
{
	char			*line;
	unsigned int	buf_len;
	char			tmp[GNL_BUFFER_LENGTH];
	int				nread;

	line = NULL;
	buf_len = GNL_BUFFER_LENGTH;
	while (--buf_len)
		tmp[buf_len] = 0;
	while (1)
	{
		nread = read(fd, &tmp, GNL_BUFFER_LENGTH);
		if (nread <= 0)
			break ;
		line = ft_append(line, buf_len, tmp, nread);
		buf_len += nread;
		if (line == NULL || tmp[nread - 1] == '\n')
			break ;
	}
	if ((nread < 0 || line == NULL) && buf_len > 0)
		free(line);
	if (nread < 0 || line == NULL)
		return (NULL);
	line = ft_append(line, (size_t) buf_len, "\0", (size_t) 1);
	return (line);
}
