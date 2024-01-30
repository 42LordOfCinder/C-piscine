/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:32:54 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/03 11:41:52 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	desc;
	int	asc;

	i = 0;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			asc++;
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			desc++;
		i++;
	}
	if (desc == i || asc == i)
		return (1);
	return (0);
}
