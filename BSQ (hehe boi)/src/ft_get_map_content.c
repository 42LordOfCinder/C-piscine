/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:33:44 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 07:13:22 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

char	*ft_get_map_content(int fd, char *file_name)
{
	char	*content;
	char	*line;
	int		size;
	int		fd1;

	if (fd < 0)
		return (0);
	size = ft_get_file_size(fd);
	if (size <= 1)
		return (0);
	content = malloc(size + 1 * sizeof(char));
	*content = 0;
	fd1 = open(file_name, O_RDWR);
	line = "a";
	while (line != NULL)
	{
		line = get_next_line(fd1);
		if (line != NULL)
			content = ft_strcat(content, line);
		free(line);
	}
	content[size] = 0;
	close(fd1);
	return (content);
}
