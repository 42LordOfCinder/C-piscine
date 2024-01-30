/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:32:37 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/01 23:08:49 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	ft_get_file_size(int fd)
{
	ssize_t	bytes;
	char	buffer[1];
	int		size;

	size = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 1);
		if (bytes < 0)
			return (-1);
		size += (int) bytes;
	}
	return (size);
}
