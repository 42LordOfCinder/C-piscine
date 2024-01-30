/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:30:51 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 20:31:47 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

void	ft_handle_args(char **argv, int is_stdin)
{
	int		i;
	int		fd;
	int		j;
	char	*content;
	char	**splitted_content;

	i = -1;
	while (argv[++i])
	{
		fd = open(argv[i], O_RDWR);
		content = ft_get_map_content(fd, argv[i]);
		splitted_content = NULL;
		if (content != 0)
			splitted_content = ft_split(content, "\n");
		if (content == 0 || !ft_check_map(content, splitted_content))
			ft_putstrerror(ERR_MAP);
		else
			ft_resolve(splitted_content);
		free(content);
		j = -1;
		while (content != 0 && splitted_content[++j])
			free(splitted_content[j]);
		free(splitted_content);
		close(fd);
	}
	if (is_stdin)
	{
		i = -1;
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}
