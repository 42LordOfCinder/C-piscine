/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:14:48 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 22:32:32 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			cmpt++;
		i++;
	}
	return (cmpt);
}
