/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:30:43 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/20 16:31:00 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_get_hexa(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
		write(1, "0", 1);
	if (nb >= 16)
	{
		ft_get_hexa(nb / 16, 0);
		ft_get_hexa(nb % 16, 0);
	}
	else
	{
		write(1, &base[nb], 1);
	}
}

void	ft_print_hexa(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i < 16)
	{
		if (tmp < 16)
			write(1, "0", 1);
		tmp /= 16;
		i++;
	}
	ft_get_hexa(addr, 0);
}

void	ft_print_text_hexa(unsigned char *addr_str, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < size)
			ft_get_hexa((unsigned long long) addr_str[i], 1);
		else if (i != 16)
			write(1, "  ", 2);
		i++;
	}
}

void	ft_print_text(unsigned char *addr_str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (addr_str[i] <= 31 || addr_str[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &addr_str[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	indent;
	unsigned int	size_to_use;
	unsigned char	*addr_str;

	indent = 0;
	addr_str = addr;
	while (indent * 16 < size)
	{
		if (indent < size / 16)
			size_to_use = 16;
		else
			size_to_use = size % 16;
		ft_print_hexa((unsigned long long) addr_str + (indent * 16));
		write(1, ":", 1);
		ft_print_text_hexa(addr_str + (indent * 16), size_to_use);
		write(1, " ", 1);
		ft_print_text(addr_str + (indent * 16), size_to_use);
		write(1, "\n", 1);
		indent++;
	}
	return (addr);
}
