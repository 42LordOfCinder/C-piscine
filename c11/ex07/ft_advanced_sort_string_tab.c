/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:54:53 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/03 16:45:13 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && (*cmp)(tmp, tab[j - 1]) < 0)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}
