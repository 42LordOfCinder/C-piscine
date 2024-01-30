/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:03:49 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/01 21:10:22 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

char	*ft_append(char *buffer, size_t buf_len, char c[], size_t nread)
{
	char	*new_buffer;
	int		i;

	if (buffer == NULL)
	{
		buffer = malloc(nread + 1);
		if (buffer == NULL)
			return (NULL);
		ft_strncpy(buffer, c, nread);
		return (buffer);
	}
	new_buffer = malloc(buf_len + nread + 1);
	if (new_buffer == NULL)
		return (NULL);
	i = -1;
	while (((unsigned int)(++i)) < buf_len)
		new_buffer[i] = buffer[i];
	free(buffer);
	ft_strncpy(new_buffer + buf_len, c, nread);
	return (new_buffer);
}
