/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:33:55 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/24 21:58:37 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

void	ft_rev_str(char *str, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size / 2)
	{
		j = str[i];
		k = str[size - i - 1];
		str[i] = k;
		str[size - i - 1] = j;
		i++;
	}
}

void	ft_insert_minus(char *str, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[0] = '-';
}

void	ft_nbr_to_base_rec(unsigned int nb, char *base, char *result, int k)
{
	int				i;
	unsigned int	size;

	size = ft_strlen(base);
	i = nb % size;
	result[k] = base[i];
	if (nb >= size)
		ft_nbr_to_base_rec(nb / size, base, result, k + 1);
}

char	*ft_nbr_to_base(int nb, char *base)
{
	char	*result;
	int		k;
	int		negative;

	negative = 0;
	result = (char *)malloc(sizeof(char) * 40);
	if (result == NULL)
		return (0);
	k = 0;
	if (nb < 0)
	{
		negative = 1;
		nb = -nb;
	}
	ft_nbr_to_base_rec((unsigned int) nb, base, result, k);
	ft_rev_str(result, ft_strlen(result));
	if (negative)
		ft_insert_minus(result, ft_strlen(result));
	return (result);
}
