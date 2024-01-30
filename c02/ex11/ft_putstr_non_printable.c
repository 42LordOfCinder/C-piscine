/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:00:08 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/17 18:42:05 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_putchar_hexa(unsigned char c)
{
	int		temp;
	int		first;
	int		second;
	char	*tab;

	temp = c;
	first = c / 16;
	second = temp % 16;
	tab = "0123456789abcdef";
	write(1, &tab[first], 1);
	write(1, &tab[second], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		if (ft_char_is_printable(str[i]))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_putchar_hexa((unsigned char) str[i]);
		}
		i++;
	}
}
