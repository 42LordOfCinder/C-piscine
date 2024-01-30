/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:57 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 20:28:24 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	**ft_alloc_tab(char **sc)
{
	int	line_count;
	int	line_len;
	int	**tab;
	int	i;

	line_count = ft_strtablen(sc);
	tab = malloc(sizeof(int *) * (line_count + 1));
	i = -1;
	line_len = ft_strlen(sc[1]);
	while (++i < line_count)
		tab[i] = malloc(sizeof(int) * line_len);
	return (tab);
}

void	ft_free_tab(int **tab, char **sc)
{
	int	line_count;
	int	i;

	line_count = ft_strtablen(sc);
	i = -1;
	while (++i < line_count)
		free(tab[i]);
	free(tab);
}

void	ft_resolve(char **sc)
{
	t_coord	ccoord;
	t_coord	maxcoord;
	int		max_value;
	int		**tab;
	int		i;

	tab = ft_alloc_tab(sc);
	max_value = 0;
	ccoord.y = 1;
	maxcoord.x = 0;
	maxcoord.y = 0;
	while (sc[ccoord.y])
	{
		ccoord.x = 0;
		while (sc[ccoord.y][ccoord.x])
		{	
			if (ft_is_obstacle(sc[ccoord.y][ccoord.x], sc[0]))
				tab[ccoord.y][ccoord.x] = 0;
			else if (ccoord.x == 0 || ccoord.y == 1)
			{
				tab[ccoord.y][ccoord.x] = 1;
				if (max_value == 0)
				{
					maxcoord.y = ccoord.y;
					maxcoord.x = ccoord.x;
					max_value = 1;
				}
			}
			else
			{
				i = tab[ccoord.y][ccoord.x - 1];
				if (tab[ccoord.y - 1][ccoord.x] < i)
					i = tab[ccoord.y - 1][ccoord.x];
				if (tab[ccoord.y - 1][ccoord.x - 1] < i)
					i = tab[ccoord.y - 1][ccoord.x - 1];
				tab[ccoord.y][ccoord.x] = i + 1;
				if (i > max_value)
				{
					maxcoord.x = ccoord.x;
					maxcoord.y = ccoord.y;
					max_value = i;
				}
			}
			ccoord.x++;
		}
		ccoord.y++;
	}
	ft_free_tab(tab, sc);
	ft_draw(sc, maxcoord, max_value);
}
